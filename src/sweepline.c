#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "geometry.h"
#include "point_tree.h"
#include "segment_tree.h"
#include "point_list.h"
#include "sweepline.h"


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
/*
void printBOOL(bool b){
    if (b){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
}*/
void findNewEvent(Segment *sL, Segment *sR, Point *p, Treenode **Q){
	// if sL and sR intersect below the sweep line, or on it and to the right of the current event point p, 
	// and the intersection is not yet present as an event in Q
	//printf("Find new event\n");
    //printSeg(sL);
    //printSeg(sR);
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
                    printf("Intersection found: (%f, %f)\n", x_inter, y_inter);
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
                printf("Intersection found: (%f, %f)\n", x_inter, y_inter);
                insertPoint(Q, inter, *Q, NULL, false);
            }
		}
	}else if (sR->p0->x != sR->p1->x){// left is vertical
		x_inter = sL->p0->x;
		y_inter = pR + mR * x_inter;
		if (y_inter > p->y || (y_inter == p->y && x_inter > p->x)){ // check si l'intersection arrive apres p dans la sweep line
            Point *inter = createPoint(x_inter, y_inter);
            if ((contains(inter,sL) || equalPoint(inter, sL->p0) || equalPoint(inter, sL->p1)) && (contains(inter,sR) || equalPoint(inter, sR->p0) || equalPoint(inter, sR->p1))){
                printf("Intersection found: (%f, %f)\n", x_inter, y_inter);
                insertPoint(Q, inter, *Q, NULL, false);
            }
		}
	}
}


Treeseg* HandleEventPoint(Point *p, Treeseg** T, ListP** Inter, Treenode **Q){
    Treeseg *Tau = *T;
    //List* L = malloc(sizeof(List));
    List* L = createVoidList();

	//List* C = malloc(sizeof(List));
    List* C = createVoidList();

	//List* RLNeigh = malloc(sizeof(List));
    List* RLNeigh = createVoidList();


	findLandC(Tau, NULL, p, false, L, C, RLNeigh);

    //printList(L);
    //printList(C);

    int lengthT = 0;
    if (p->U != NULL){lengthT += p->U->length;}
    if (L != NULL){lengthT += L->length;}
    if (C != NULL){lengthT += C->length;}
    //printf("%d\n",lengthT);

    if (lengthT >= 2){// p is an intersection point
        //printf("Intersection found\n");
		insertListHeadP(*Inter, p, concatenate(p->U, L, C));
	}

	//Delete segment with p as lower point from the tree
    if (L != NULL){
        for(int i=0; i<(L->length); i++){
            //printf("deleting segment %d from L\n", i);
            delSeg(&Tau, L->head->value, p);
            delHead(L);
            //freeListSeg(L->head);
        }
    }

    //Delete and reinsert segment containing p from the tree (so they switch positions)
	if (C != NULL){
        delForC(&Tau, C->head, p);
        insertForC(&Tau, C->head, p);
    }
    //printf("List C handeled\n");


    //Insert segment with p as upper point
    if (p->U != NULL) {
        insertForU(&Tau, p->U->head, p);
    }
    //printf("List U handeled\n");

    //printTreeseg(Tau);

    // Check for new intersections
	if (p->U->length + C->length == 0){// p is only a lower point
		if (RLNeigh->length == 2){// sl and sr exists
			findNewEvent(RLNeigh->head->value, RLNeigh->queue->value, p, Q);
		}
	}else{
		/*Segment* LeftMost = malloc(sizeof(Segment));
		Segment* RightMost = malloc(sizeof(Segment));
		Segment* LeftNeigh = malloc(sizeof(Segment));
		Segment* RightNeigh = malloc(sizeof(Segment));*/

        Segment* LeftMost = findLeftMost(Tau, NULL, p, false);
        Segment* RightMost = findRightMost(Tau, NULL, p, false);
        Segment* LeftNeigh = NULL;
        Segment* RightNeigh= NULL;

        if (LeftMost != NULL){
            LeftNeigh = findLeftNb(Tau, LeftMost, p, false)->value;
        }
        if (RightMost != NULL){
            RightNeigh = findRightNb(Tau, RightMost, p, false)->value;
        }

		if (LeftNeigh != NULL){
			findNewEvent(LeftNeigh, LeftMost, p, Q);
		}
		if (RightNeigh != NULL){
			findNewEvent(RightNeigh, RightMost, p, Q);
		}
        /*
        freeSeg(LeftMost);
        freeSeg(RightMost);
        freeSeg(LeftNeigh);
        freeSeg(RightNeigh);*/
	}
    /*freeList(L);
    freeList(C);
    freeList(RLNeigh);*/
    return Tau;
}


ListP* FindIntersections(List* s){ //<- list of segments 
	// 1- checkSegment to sort segemnts -- ease process for Upper/Lower points (v)
	// 2 - (p, list s) -> return s(starting = p)  <---- donner aux segment.value la valeur de Upper Point  <<< tous les points qui vont être dans l'arbre Q
	// 3 - creer l'arbre Q avec tous les points
    //printList(s);
    Treenode *Q = NULL;
	createQ(s->head, &Q);
    //printTree(Q);


	Treeseg *Tau = NULL; // tous les points qui sont sur L (sweepline)
	//printf("Tau has been created\n");

	ListP* Intersections = createVoidListP();
	//printf("list Intersection has been created\n");
    Point *p = NULL;
	while(Q != NULL){
        p = delPoint(&Q);
        printf("\n\n");
        printPoint(p);
        //printTree(Q);
		Tau = HandleEventPoint(p, &Tau, &Intersections, &Q);
        //printf("Point handeled\n");
        //freePoint(p);
        //printf("Point handled\n");
	}
	//check all point which y <line 
	// is their p1 lower ?

    //freeTreeseg(Tau);
	//freeTreenode(Q);
    //freePoint(p);
	return Intersections;
}


