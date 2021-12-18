#ifndef SWEEPLINE_H_
#define SWEEPLINE_H_

//#include "BOV.h"
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "geometry.h"
#include "point_tree.h"
#include "segment_tree.h"
#include "point_list.h"
#include "BOV.h"

typedef struct dataStruct{
    struct ListP *Intersections;
    struct Treenode *Q;
    struct Treeseg *Tau;
    struct Point *p;
} dataStruct;

dataStruct* initDataStruct();
void delForC(Treeseg**, Listseg*, Point*);
void insertForC(Treeseg**, Listseg*, Point*);
void insertForU(Treeseg**, Listseg*, Point*);
void createQ(Listseg*, Treenode**);

void findNewEvent(Segment*, Segment*, Point*, Treenode**,dataStruct*);

Treeseg* HandleEventPoint(Point*, Treeseg**, ListP**, Treenode**, dataStruct*);

ListP* FindIntersections(List*, dataStruct*);
ListP* FindIntersections2(List*, dataStruct*, Point*);


List* fromTab2List(GLfloat[][2], GLsizei);
void fromListP2Tab(ListP*, GLfloat[][2]);
//GLfloat* fromTreeseg2Tab(Treeseg*);
//GLfloat* fromTreenode2Tab(Treenode*);
bool fromTreeseg2ListP(ListP*, Treeseg*);
bool fromTreenode2ListP(ListP*, Treenode*);
#endif