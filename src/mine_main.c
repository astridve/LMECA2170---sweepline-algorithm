#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "inputs.h"
//include "translate.h"
#include "geometry.h"
#include "sweepline.h"

List* toSegList(GLfloat coord[][2], GLsizei nPoints){
	//List* segmentList = malloc(sizeof(List));
    List* segmentList = createVoidList();

	for (GLsizei i=0; i<nPoints; i+=2) {
		insertListHead(segmentList, createSegment(createPoint(coord[i][0], -coord[i][1]), createPoint(coord[i+1][0], -coord[i+1][1]), i/2));
	}
		
	return segmentList;
}

/*
int main() {
	const GLsizei nPoints = 10;
	GLfloat (*coord)[2] = malloc(sizeof(coord[0])*nPoints);

	random_points(coord, nPoints);
	List* segmentList = fromTab2List(coord, nPoints);
    FindIntersections(segmentList);
	free(segmentList);
}*/


int main(int argc, char* argv[])
{
	// give a bit of entropy for the seed of rand()
	// or it will always be the same sequence
	int seed = (int) time(NULL);
	srand(seed);

	// we print the seed so you can get the distribution of points back
	printf("seed=%d\n", seed);

    /*bov_window_t* window = bov_window_new(0, 0, argv[0]);
    bov_window_enable_help(window);

    // a grey background
    bov_window_set_color(window, (GLfloat[4]) { 0.9, 0.9, 0.9, 1 });
    */

    const GLsizei nPoints = 10000;
    /*
    GLfloat coord[14][2] = {
            {0.0, -0.4},
            {0.5,  0.0},
            {0.3,  0.0},
            {0.0, -0.9},
            {0.8, -0.6},
            {1.0,  0.0},
            {0.9,  0.3},
            {0.0,  0.8},
            {0.7,  0.6},
            {0.5, -0.6},
            {0.4, 0.6},
            {0.1, -0.9},
            {9, -10},
            {7, 3}
    };
    GLfloat coord[4][2] = {
            {-1, 1},
            {1,  -1},
            {-1,  -1},
            {1, 1},
    };*/
	GLfloat (*coord)[2] = malloc(sizeof(coord[0])*nPoints);

    GLfloat range = 5;
    //random_uniform_points(coord, nPoints, (GLfloat[2]) {-range, -range}, (GLfloat[2]) { range,  range});
    random_points(coord, nPoints);

    /*
    bov_points_t* segment = bov_points_new(coord, nPoints, GL_STATIC_DRAW);

    // we want to keep the window open with everything displayed...
    while (!bov_window_should_close(window)) {
        // segments
        bov_lines_draw(window, segment, 0, nPoints);

        bov_window_update(window);
    }

    end_of_program:

    printf("Ended correctly - %.2f second\n", window->wtime);

    bov_points_delete(segment);
    bov_window_delete(window);*/

    //#############################################################################################################
    dataStruct* data = initDataStruct();
    List* segmentList = toSegList(coord, nPoints);
    ListP* intersections = FindIntersections(segmentList, data);
    printListP(intersections);
    //freeList(segmentList);


    return EXIT_SUCCESS;
}




