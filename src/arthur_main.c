#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "inputs.h"
#include "geometry.h"
#include "sweepline.h"

int main(int argc, char* argv[])
{
    bool image = false; // overrid other options
    bool animation = true;
    bool on_click = true;

    // defining segments
    const GLsizei nPoints = 16; // --- has to be even !

    int seed = 1639935196;//(int)time(NULL);

    printf("[MAIN] seed : %d\n",seed);
    srand(seed);
    GLfloat(*segment_coord)[2] = malloc(sizeof(segment_coord[0]) * nPoints);
    random_points(segment_coord, nPoints);

    // conversion to segment list
    List* segmentList = fromTab2List(segment_coord, nPoints);

    // main program
    if (!animation && !image) {// if not animated --> fast computation
        // data container
        dataStruct* data = initDataStruct();

        data->Intersections = FindIntersections(segmentList, data);
        printf("%d",data->Intersections->length);
        freeDatastruct(data);
        freeList(segmentList);
        return EXIT_SUCCESS;
    }

    //%%%%%%%%% D E S I G N %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    bov_window_t* window = bov_window_new(618 * 2, 162 * 5, argv[0]);     // --- window dimensions
    bov_window_set_color(window, (GLfloat[4]) { 1.0f, 1.0f, 1.0f, 1.0f});  // --- background colors
    // %%% --- basic segments
    bov_points_param_t segmentParams = {
            .fillColor = {0.0f, 0.0f, 0.0f, 1.0f},
            .outlineColor = {0.0f ,0.0f, 0.0f, 0.5f},
            .scale = {1.0, 1.0},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t pointParams = {
            .fillColor = {0.0f, 0.0f, 0.0f, 1.0f},
            .outlineColor = {0.0f ,0.0f, 0.0f, 0.25f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    bov_points_t* segment = bov_points_new(segment_coord, nPoints, GL_STATIC_DRAW);
    bov_points_set_param(segment, segmentParams);
    bov_points_t* point = bov_points_new(segment_coord, nPoints, GL_STATIC_DRAW);
    bov_points_set_param(point, pointParams);
    // %%% --- red point (point p of the algorythm)
    // GLfloat p_coord[1][2] = { {(float) data->p->x, (float) data->p->y} }; // <---- BUGGY car data-> p est encore NULL
    GLfloat p_coord[1][2] = { {-1000.0f, -1000.0f} }; //TODO: when to free?
    bov_points_param_t pParams = {
            //.fillColor = {0.839f, 0.411f, 0.388f, 1.0f},
            .fillColor = {1.0f , 0.6549f, 0.0f, 1.0f},
            .outlineColor = {0.839f, 0.411f, 0.388f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.025f,
            .outlineWidth = 0.005f
    };
    bov_points_t* p = bov_points_new(p_coord, 1, GL_STATIC_DRAW);
    bov_points_set_param(p, pParams);
    //// %%% --- sweepline
    GLfloat sweepline_coord[2][2] = {
            {-1000.0, 0.0},
            { 1000.0,  0.0 } // where to initialize ?
    };
    bov_points_param_t sweeplineParams = {
            .fillColor = {0.0f, 0.34f, 0.905f, 1.0f},
            .outlineColor = {0.0f, 0.34f, 0.905f, 0.166f},
            .scale = {1.0f, 1.0f},
            .width = 0.012f,
            .outlineWidth = 0.005f
    };
    bov_points_t* sweepline = bov_points_new(sweepline_coord, 2, GL_STATIC_DRAW);
    bov_points_set_param(sweepline, sweeplineParams);
    // %%% --- intersection points
    bov_points_param_t intersectionParams = {
            .fillColor = {0.0f, 0.0f, 0.0f, 0.0f},
            .outlineColor = {0.839f, 0.176f, 0.125f, 1.0f},
            //.outlineColor = {0.9529f ,0.71f, 0.321f, 1.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.025f,
            .outlineWidth = 0.005f
    };
    // %%% --- tau segments
    bov_points_param_t tauParams = {
            .fillColor = {1.0f, 0.53f, 0.266f, 0.0f},
            .outlineColor = {1.0f, 0.0f, 0.0f, 1.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    // %%% --- RightNeigh and RightMost segments
    bov_points_param_t smsrParams = {
            .fillColor = {0.0f, 1.00f, 1.0f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t psmsrParams = {
            .fillColor = {0.0f, 1.00f, 1.0f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    // %%% --- LeftNeigh and LeftMost segments
    bov_points_param_t smslParams = {
            .fillColor = {1.0f, 1.0f, 0.0f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t psmslParams = {
            .fillColor = {1.0f, 1.0f, 0.0f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    // %%% --- RLN segments
    bov_points_param_t smsParams = {
            .fillColor = {1.0f, 0.0f, 1.0f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t psmsParams = {
            .fillColor = {1.0f, 0.0f, 1.0f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    //%%%%%%%%% END of DESIGN %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    if (image) {
        // data container
        dataStruct* data = initDataStruct();
        data->Intersections = FindIntersections(segmentList, data);
        while (!bov_window_should_close(window)) {
            bov_lines_draw(window, segment, 0, nPoints);
            bov_points_draw(window, point, 0, nPoints);

            // update intersections
            GLfloat(*intersection_coord)[2] = malloc(sizeof(segment_coord[0]) * data->Intersections->length);
            fromListP2Tab(data->Intersections, intersection_coord);
            bov_points_t* intersection = bov_points_new(intersection_coord, data->Intersections->length, GL_STATIC_DRAW);
            bov_points_set_param(intersection, intersectionParams);
            if (nPoints >= 100) {
                bov_points_set_color(intersection, (GLfloat[4]) { 0.839f, 0.176f, 0.125f, 1.0f });
                bov_points_set_outline_color(intersection, (GLfloat[4]) { 0.839f, 0.176f, 0.125f, 0.0f });
                bov_points_set_outline_width(intersection, 0.005);
                bov_points_set_width(intersection, 0.01);
            }
            bov_points_draw(window, intersection, 0, data->Intersections->length);
            bov_points_delete(intersection);
            free(intersection_coord);

            // others
            bov_window_update(window);
        }
        printf("%d",data->Intersections->length);
        freeDatastruct(data);
        freeList(segmentList);
        free(segment_coord);
        return EXIT_SUCCESS;
    }

    // running the window for animation
    if(animation && !image) {
        bool prevent_first_click = false;
        bool curr_click = false;
        Point* last_p = createPoint(-730957.0, -137532384.0, NULL);

        // data container
        dataStruct *data = initDataStruct();
        if(data->p == NULL) { data->p = createPoint(0.0, -1000.0, NULL); }
        while (!bov_window_should_close(window)) {
            bov_lines_draw(window, segment, 0, nPoints);
            bov_points_draw(window, point, 0, nPoints);

            if (on_click) { // click event interception
                if ((window->clickTime[0] < -window->wtime + 0.025f && window->clickTime[0] > -window->wtime - 0.025f) && !prevent_first_click) {
                    curr_click = true;
                    printf("\n >>> click <<<\n");

                    if (! equalPoint(last_p, data->p)) {
                        free(last_p);
                        last_p = createPoint(data->p->x, data->p->y, data->p->U);
                        FindIntersections2(segmentList, data, data->p);
                    }
                    else { break; }

                    // aller chercher le prochain point dans Q ...
                    p_coord[0][0] = (float) data->p->x;
                    p_coord[0][1] = (float) -data->p->y;

                }
                if (prevent_first_click) {
                    prevent_first_click = false;
                }
            } else {
                if (!equalPoint(last_p, data->p)) {
                    free(last_p);
                    last_p = createPoint(data->p->x, data->p->y, data->p->U);
                    FindIntersections2(segmentList, data, data->p);
                }
                else { break; }
                // aller chercher le prochain point dans Q ...
                p_coord[0][0] = (float) data->p->x;
                p_coord[0][1] = (float) -data->p->y;
            }

            // update Tau
            /*if (data->Tau != NULL) {
                GLfloat(*tau_coord)[2] = malloc(sizeof(tau_coord[0]) * TreesegSize(data->Tau));
                fromTreeseg2Tab(data->Tau, tau_coord);
                bov_points_t *tau = bov_points_new(tau_coord, (int) sizeof(tau_coord) / 2, GL_STATIC_DRAW);
                bov_points_set_param(tau, tauParams);
                bov_lines_draw(window, tau, 0, data->Intersections->length);
                bov_points_delete(tau);
                free(tau_coord);
            }*/

            // update LeftMost/LeftNeigh and RightMost/RightNeigh Segments
            if (data->RLN != NULL) {
                ListP *SMS = createVoidListP();
                for (Listseg *curr = data->RLN->head; curr != NULL; curr = curr->prev) {
                    insertListHeadP(SMS, curr->value->p0, NULL);
                    insertListHeadP(SMS, curr->value->p1, NULL);
                }

                GLfloat(*sms_coord)[2] = malloc(sizeof(sms_coord[0]) * SMS->length);
                fromListP2Tab(SMS, sms_coord);
                bov_points_t *sms = bov_points_new(sms_coord, sizeof(sms_coord), GL_STATIC_DRAW);
                bov_points_set_param(sms, smsParams);
                bov_lines_draw(window, sms, 0, SMS->length);
                bov_points_delete(sms);
                freeListP(SMS);
                free(sms_coord);
            }
            if (data->RM != NULL || data->RN != NULL) {
                ListP *SMSR = createVoidListP();
                if (data->RM != NULL) {
                    insertListHeadP(SMSR, data->RM->p0, NULL);
                    insertListHeadP(SMSR, data->RM->p1, NULL);
                }
                if (data->RN != NULL) {
                    insertListHeadP(SMSR, data->RN->p0, NULL);
                    insertListHeadP(SMSR, data->RN->p1, NULL);
                }
                GLfloat(*smsr_coord)[2] = malloc(sizeof(smsr_coord[0]) * SMSR->length);
                fromListP2Tab(SMSR, smsr_coord);
                bov_points_t *smsr = bov_points_new(smsr_coord, sizeof(smsr_coord), GL_DYNAMIC_DRAW);
                bov_points_set_param(smsr, smsrParams);
                bov_lines_draw(window, smsr, 0, SMSR->length);
                bov_points_t *psmsr = bov_points_new(smsr_coord, sizeof(smsr_coord), GL_DYNAMIC_DRAW);
                bov_points_set_param(smsr, psmsrParams);
                bov_points_draw(window, smsr, 0, SMSR->length);
                bov_points_delete(smsr);
                bov_points_delete(psmsr);
                freeListP(SMSR);
                free(smsr_coord);
            }
            if (data->LM != NULL || data->LN != NULL) {
                ListP *SMSL = createVoidListP();
                if (data->LM != NULL) {
                    insertListHeadP(SMSL, data->LM->p0, NULL);
                    insertListHeadP(SMSL, data->LM->p1, NULL);
                }
                if (data->LN != NULL) {
                    insertListHeadP(SMSL, data->LN->p0, NULL);
                    insertListHeadP(SMSL, data->LN->p1, NULL);
                }
                GLfloat(*smsl_coord)[2] = malloc(sizeof(smsl_coord[0]) * SMSL->length);
                fromListP2Tab(SMSL, smsl_coord);
                bov_points_t *smsl = bov_points_new(smsl_coord, sizeof(smsl_coord), GL_STATIC_DRAW);
                bov_points_set_param(smsl, smslParams);
                bov_lines_draw(window, smsl, 0, SMSL->length);
                bov_points_delete(smsl);
                freeListP(SMSL);
                free(smsl_coord);
            }


            // update intersections
            GLfloat(*intersection_coord)[2] = malloc(sizeof(segment_coord[0]) * data->Intersections->length);
            fromListP2Tab(data->Intersections, intersection_coord);
            bov_points_t *intersection = bov_points_new(intersection_coord, data->Intersections->length, GL_STATIC_DRAW);
            bov_points_set_param(intersection, intersectionParams);
            if (nPoints >= 100) {
                bov_points_set_color(intersection, (GLfloat[4]) {0.839f, 0.176f, 0.125f, 1.0f});
                bov_points_set_outline_color(intersection, (GLfloat[4]) {0.839f, 0.176f, 0.125f, 0.0f});
                bov_points_set_outline_width(intersection, 0.005);
                bov_points_set_width(intersection, 0.015);
            }
            bov_points_draw(window, intersection, 0, data->Intersections->length);
            bov_points_delete(intersection);
            free(intersection_coord);

            // update sweepline
            sweepline_coord[0][1] = p_coord[0][1];
            sweepline_coord[1][1] = p_coord[0][1];
            sweepline = bov_points_new(sweepline_coord, 2, GL_STATIC_DRAW);
            bov_points_set_param(sweepline, sweeplineParams);
            bov_lines_draw(window, sweepline, 0, 2);
            bov_points_delete(sweepline);

            // redraw point p in red over sweepline
            p = bov_points_new(p_coord, 1, GL_STATIC_DRAW);
            bov_points_set_param(p, pParams);
            bov_points_draw(window, p, 0, 1);
            bov_points_delete(p);

            // others
            curr_click = false;
            bov_window_update(window);

            /*freePoint(last_p);
            last_p = createPoint(data->p->x, data->p->y, data->p->U);
            freeDatastruct(data);*/
        }
    }


    return EXIT_SUCCESS;
}