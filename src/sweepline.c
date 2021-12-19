#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "geometry.h"
#include "point_tree.h"
#include "segment_tree.h"
#include "point_list.h"
#include "sweepline.h"


dataStruct* initDataStruct(){
    dataStruct *result = malloc(sizeof(dataStruct));
    if (result != NULL) {
        result->Intersections = createVoidListP();
        result->Q = NULL;
        result->Tau = NULL;
        result->p = NULL;
        result->LM = NULL;
        result->RM = NULL;
    }
    return result;
}

void delForC(Treeseg** Tau, Listseg* Ci, Point* p){
    if (Ci != NULL){
        delSeg(Tau, Ci->value, p);
        delForC(Tau, Ci->prev, p);
    }
}

void insertForC(Treeseg** Tau, Listseg* Ci, Point* p){
    if (Ci !=  NULL){
        insertSeg(Tau, p, Ci->value, *Tau);
        insertForC(Tau, Ci->prev, p);
    }
}

void insertForU(Treeseg** Tau, Listseg* Ui, Point* p){
    if (Ui != NULL){
        insertSeg(Tau, p, Ui->value, *Tau);
        insertForU(Tau, Ui->prev, p);
    }
}

void createQ(Listseg* s, Treenode** Q){
    if (s != NULL){
        insertPoint(Q, s->value->p0, *Q, s->value, true); // <- update si p0 already dans le tree
        insertPoint(Q, s->value->p1, *Q, s->value, false);
        createQ(s->prev, Q);
    }
}


void findNewEvent(Segment *sL, Segment *sR, Point *p, Treenode **Q, dataStruct *data){

    double mL, mR;
    double pL, pR;

    double x_inter, y_inter;

    if (sL->p0->x != sL->p1->x){//sL not vertical
        mL = (sL->p0->y - sL->p1->y) / (sL->p0->x - sL->p1->x);
        pL = sL->p0->y - mL * sL->p0->x;
    }
    if (sR->p0->x != sR->p1->x){//sR not vertical
        mR = (sR->p0->y - sR->p1->y) / (sR->p0->x - sR->p1->x);
        pR = sR->p0->y - mR * sR->p0->x;
    }

    if ((sL->p0->x != sL->p1->x) && (sR->p0->x != sR->p1->x)){ // deux segment non verticaux
        if (mL != mR){// si deux segments sont l'un sur l'autre on ne reporte pas d'intersections!
            x_inter = (pL - pR) / (mR - mL);
            y_inter = pL + mL * x_inter;
            if (y_inter > p->y || (y_inter == p->y && x_inter > p->x)){ // check si l'intersection arrive apres p dans la sweep line
                Point *inter = createPoint(x_inter, y_inter);
                if ((contains(inter,sL) || equalPoint(inter, sL->p0) || equalPoint(inter, sL->p1)) && (contains(inter,sR) || equalPoint(inter, sR->p0) || equalPoint(inter, sR->p1))){
                    printf("INTERSECTION\n");
                    printPoint(inter);
                    insertPoint(Q, inter, *Q, NULL, false);
                }
            }
        }
    }else if (sL->p0->x != sL->p1->x){// right is vertical
        x_inter = sR->p0->x;
        y_inter = pL + mL * x_inter;
        if (y_inter > p->y || (y_inter == p->y && x_inter > p->x)){ // check si l'intersection arrive apres p dans la sweep line
            Point *inter = createPoint(x_inter, y_inter);
            if ((contains(inter,sL) || equalPoint(inter, sL->p0) || equalPoint(inter, sL->p1)) && (contains(inter,sR) || equalPoint(inter, sR->p0) || equalPoint(inter, sR->p1))){
                printf("INTERSECTION\n");
                printPoint(inter);
                insertPoint(Q, inter, *Q, NULL, false);

            }
        }
    }else if (sR->p0->x != sR->p1->x){// left is vertical
        x_inter = sL->p0->x;
        y_inter = pR + mR * x_inter;
        if (y_inter > p->y || (y_inter == p->y && x_inter > p->x)){ // check si l'intersection arrive apres p dans la sweep line
            Point *inter = createPoint(x_inter, y_inter);
            if ((contains(inter,sL) || equalPoint(inter, sL->p0) || equalPoint(inter, sL->p1)) && (contains(inter,sR) || equalPoint(inter, sR->p0) || equalPoint(inter, sR->p1))){
                printf("INTERSECTION\n");
                printPoint(inter);
                insertPoint(Q, inter, *Q, NULL, false);
            }
        }
    }
}


Treeseg* HandleEventPoint(Point *p, Treeseg** T, ListP** Inter, Treenode **Q, dataStruct *data){
    Treeseg *Tau = *T;

    List* L = createVoidList();
    List* C = createVoidList();
    List* RLNeigh = createVoidList();

    findLandC(Tau, NULL, p, false, L, C, RLNeigh);

    printList(L);
    printList(C);

    int lengthT = p->U->length + L->length + C->length;
    if (lengthT >= 2){// p is an intersection point
        insertListHeadP(*Inter, p, concatenate(p->U, L, C));
    }

    //Delete segment with p as lower point from the tree
    for (int i = 0; i < (L->length); i++) {
        delSeg(&Tau, L->head->value, p);
        delHead(L);
    }

    //Delete and reinsert segment containing p from the tree (so they switch positions)
    delForC(&Tau, C->head, p);
    insertForC(&Tau, C->head, p);

    //Insert segment with p as upper point
    if (p->U != NULL) {
        insertForU(&Tau, p->U->head, p);
    }

    printTreeseg(Tau);

    // Check for new intersections
    if (p->U->length + C->length == 0){// p is only a lower point
        printf("ONLY LOWER\n");
        printList(RLNeigh);
        data->LM = NULL;
        data->RM = NULL;
        if (RLNeigh->length == 2){// sl and sr exists
            findNewEvent(RLNeigh->head->value, RLNeigh->queue->value, p, Q, data);
        }
    }else{
        Segment* LeftMost = findLeftMost(Tau, NULL, p, false);
        Segment* RightMost = findRightMost(Tau, NULL, p, false);
        Segment* LeftNeigh = NULL;
        Segment* RightNeigh= NULL;

        if (LeftMost != NULL){
            data->LM = createSegment(createPoint(LeftMost->p0->x, LeftMost->p0->y), createPoint(LeftMost->p1->x, LeftMost->p1->y), -120810347);
            LeftNeigh = findLeftNb(Tau, LeftMost, p, false)->value;
        }else{
            data->LM = NULL;
        }

        if (RightMost != NULL){
            data->RM = createSegment(createPoint(RightMost->p0->x, RightMost->p0->y), createPoint(RightMost->p1->x, RightMost->p1->y), -12471037);
            RightNeigh = findRightNb(Tau, RightMost, p, false)->value;
        }else{
            data->RM = NULL;
        }

        if (LeftNeigh != NULL){
            printf("LEFT CHECK\n");
            printSeg(LeftMost);
            printSeg(LeftNeigh);
            findNewEvent(LeftNeigh, LeftMost, p, Q, data);
        }
        if (RightNeigh != NULL){
            printf("RIGHT CHECK\n");
            printSeg(RightMost);
            printSeg(RightNeigh);
            findNewEvent(RightNeigh, RightMost, p, Q, data);
        }
    }
    return Tau;
}


ListP* FindIntersections(List* s, dataStruct *data){
    Treenode *Q = NULL;
    createQ(s->head, &Q);
    data->Q = Q;

    Treeseg *Tau = NULL;
    data->Tau = Tau;

    ListP* Intersections = createVoidListP();
    data->Intersections = Intersections;

    Point *p = NULL;

    while(Q != NULL){
        p = delPoint(&Q);
        printf("\n\n");
        printPoint(p);
        Tau = HandleEventPoint(p, &Tau, &Intersections, &Q, data);
    }

    //freeTreeseg(Tau);
    //freeTreenode(Q);
    //freePoint(p);
    return Intersections;
}

ListP* FindIntersections2(List* s, dataStruct *data, Point* red_point){
    Treenode *Q = NULL;
    createQ(s->head, &Q);
    data->Q = Q;

    Treeseg *Tau = NULL;
    data->Tau = Tau;

    //ListP* Intersections = createVoidListP();
    data->Intersections = createVoidListP();

    Point *p = NULL;

    bool avant_dernier = false;
    while(Q != NULL){
        p = delPoint(&Q);
        data->p = p;
        printf("\n\n\n\n");
        printPoint(p);
        Tau = HandleEventPoint(p, &Tau, &(data->Intersections), &Q, data);

        if(avant_dernier){
            break;
        }
        if(red_point->y < p->y || (red_point->y == p->y && red_point-> x <= p->x)){
            avant_dernier = true;
        }
    }
    //freeTreeseg(Tau);
    //freeTreenode(Q);
    //freePoint(p);
    return data->Intersections;
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%             CONVERTERS Tab - Tree - List
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
List* fromTab2List(GLfloat coord[][2], GLsizei nPoints){
    List* segmentList = createVoidList();
    for (GLsizei i=0; i<nPoints; i+=2) {
        insertListHead(segmentList, createSegment(createPoint(coord[i][0], -coord[i][1]), createPoint(coord[i+1][0], -coord[i+1][1]), i/2));
    }
    return segmentList;
}

bool fromListP2Tab(ListP* list, GLfloat coord[][2]){
    if (list->head == NULL) {return false; }
    int i = 0;
    for (Listpoint* curr = list->head; curr != NULL; curr = curr->prev) {
        coord[i][0] = (GLfloat)curr->value->x;
        coord[i][1] = -(GLfloat)curr->value->y;
        i += 1;
    }
    return true;
}


bool fromTreenode2ListP(ListP* list, Treenode* tree){
    if(tree == NULL){
        return false;
    }
    if(tree->value != NULL){
        insertListHeadP(list, tree->value, NULL);
        if(tree->right != NULL){
            fromTreenode2ListP(list, tree->right);
        }
        if(tree->left != NULL){
            fromTreenode2ListP(list, tree->left);
        }
        return true;
    }else{
        return true;
    }
}

bool fromTreeseg2ListP(ListP* list, Treeseg* tree){
    if(tree == NULL){
        return false;
    }
    if(tree->value != NULL){
        insertListHeadP(list, tree->value->p0, NULL);
        insertListHeadP(list, tree->value->p1, NULL);
        if(tree->right != NULL){
            fromTreeseg2ListP(list, tree->right);
        }
        if(tree->left != NULL){
            fromTreeseg2ListP(list, tree->left);
        }
        return true;
    }else{
        return true;
    }
}

bool fromTreenode2Tab(Treenode* tree, GLfloat tab[][2]){
    ListP* list = createVoidListP();
    fromTreenode2ListP(list, tree);
    fromListP2Tab(list, tab);
    return true;
}

bool fromTreeseg2Tab(Treeseg* tree, GLfloat tab[][2]){
    ListP* list = createVoidListP();
    fromTreeseg2ListP(list, tree);
    fromListP2Tab(list, tab);
    return true;
}

int TreesegSize(Treeseg* tree) {
    ListP* list = createVoidListP();
    fromTreeseg2ListP(list, tree);
    return list->length;
}


int TreenodeSize(Treenode* tree) {
    ListP* list = createVoidListP();
    fromTreenode2ListP(list, tree);
    return list->length;
}