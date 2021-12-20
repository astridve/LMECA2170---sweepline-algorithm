#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "inputs.h"
#include "geometry.h"
#include "sweepline.h"
#include "string.h"

int main(int argc, char* argv[])
{
    /*                                                                                                                                        
        88888888ba          db         88888888ba          db         88b           d88  88888888888  888888888888  88888888888  88888888ba    ad88888ba   
        88      "8b        d88b        88      "8b        d88b        888b         d888  88                88       88           88      "8b  d8"     "8b  
        88      ,8P       d8'`8b       88      ,8P       d8'`8b       88`8b       d8'88  88                88       88           88      ,8P  Y8,          
        88aaaaaa8P'      d8'  `8b      88aaaaaa8P'      d8'  `8b      88 `8b     d8' 88  88aaaaa           88       88aaaaa      88aaaaaa8P'  `Y8aaaaa,    
        88""""""'       d8YaaaaY8b     88""""88'       d8YaaaaY8b     88  `8b   d8'  88  88"""""           88       88"""""      88""""88'      `"""""8b,  
        88             d8""""""""8b    88    `8b      d8""""""""8b    88   `8b d8'   88  88                88       88           88    `8b            `8b  
        88            d8'        `8b   88     `8b    d8'        `8b   88    `888'    88  88                88       88           88     `8b   Y8a     a8P  
        88           d8'          `8b  88      `8b  d8'          `8b  88     `8'     88  88888888888       88       88888888888  88      `8b   "Y88888P"                                                  
    */

    // - display
    bool image = false;                     // image set on true overrides other displaying options
    bool animation = true;
    bool on_click = true;

    bool fullscreen = true;                 // fullscreen is forced for automated animation  (without click)

    // - max speed
    float dt = 1.5;                      // [ms] for animation without click

    // defining segments
    const GLsizei nPoints = 18;             // --- has to be even and below 100 if you want to animate it !


    //int seed = (int)time(NULL);

    //printf("[MAIN] seed : %d\n",seed);
    //srand(seed);
    //GLfloat(*segment_coord)[2] = malloc(sizeof(segment_coord[0]) * nPoints);
    //random_points(segment_coord, nPoints);


    // TODO - define a well-predefined segment list
    // JUST FOR YOU -  a well-predefined segment list   ( Merry Christmas ! )
    GLfloat segment_coord[18][2] = {
            {0.087f,  0.364f}, //A
            {0.284f,  0.322f}, //B
            {0.421f,  0.279f}, //C
            {0.300f,  0.150f}, //D
            {0.770f,  0.100f}, //E
            {0.250f,  0.350f}, //F
            {0.477f,  0.261f}, //G
            {0.359f,  0.213f}, //H
            {0.359f,  0.080f}, //I
            {0.470f,  0.123f}, //J
            {0.044f,  0.307f}, //K
            {0.071f,  0.253f}, //L
            {0.569f,  0.308f}, //M
            {0.624f,  0.239f}, //N
            {0.569f,  0.308f}, //M
            {0.550f,  0.220f}, //O
            {0.550f,  0.220f}, //O
            {0.624f,  0.239f}, //N
    };
    // -- don't forget to adapt the value of the "nPoints" variable above to : 18






    List* segmentList = fromTab2List(segment_coord, nPoints);










/*
                                                                                                    _  \ \
      _ __     ___    _ __    ______   _   _   ___    ___   _ __     ____   ___    _ __     ___    (_)  | |
     | '_ \   / _ \  | '_ \  |______| | | | | / __|  / _ \ | '__|   |_  /  / _ \  | '_ \   / _ \        | |
     | | | | | (_) | | | | |          | |_| | \__ \ |  __/ | |       / /  | (_) | | | | | |  __/    _   | |
     |_| |_|  \___/  |_| |_|           \__,_| |___/  \___| |_|      /___|  \___/  |_| |_|  \___|   (_)  | |
                                                                                                       /_/
*/
















    fullscreen = (animation && !on_click) || fullscreen; // fullscreen is forced for automated display


    /*
        88888888888         db          ad88888ba   888888888888      88888888ba   88        88  888b      88
        88                 d88b        d8"     "8b       88           88      "8b  88        88  8888b     88  
        88                d8'`8b       Y8,               88           88      ,8P  88        88  88 `8b    88  
        88aaaaa          d8'  `8b      `Y8aaaaa,         88           88aaaaaa8P'  88        88  88  `8b   88
        88"""""         d8YaaaaY8b       `"""""8b,       88           88""""88'    88        88  88   `8b  88  
        88             d8""""""""8b            `8b       88           88    `8b    88        88  88    `8b 88
        88            d8'        `8b   Y8a     a8P       88           88     `8b   Y8a.    .a8P  88     `8888  
        88           d8'          `8b   "Y88888P"        88           88      `8b   `"Y8888Y"'   88      `888
    */

    if (!animation && !image) {// if not animated --> fast computation
        // data container
        dataStruct* data = initDataStruct();

        data->Intersections = FindIntersections(segmentList, data);
        printf("[MAIN] Number of intersection found : %d",data->Intersections->length);
        freeDatastruct(data);
        freeList(segmentList);
        return EXIT_SUCCESS;
    }







    /*
        88888888ba,    88888888888   ad88888ba   88    ,ad8888ba,   888b      88  
        88      `"8b   88           d8"     "8b  88   d8"'    `"8b  8888b     88  
        88        `8b  88           Y8,          88  d8'            88 `8b    88  
        88         88  88aaaaa      `Y8aaaaa,    88  88             88  `8b   88  
        88         88  88"""""        `"""""8b,  88  88      88888  88   `8b  88  
        88         8P  88                   `8b  88  Y8,        88  88    `8b 88  
        88      .a8P   88           Y8a     a8P  88   Y8a.    .a88  88     `8888  
        88888888Y"'    88888888888   "Y88888P"   88    `"Y88888P"   88      `888  
                                                                          
    */
    bov_window_t* window;
    if (fullscreen) {
        window = bov_window_new(0, 0, argv[0]);
    }
    else {
        window = bov_window_new(618 * 2, 162 * 5, argv[0]);
    }
    bov_window_set_color(window, (GLfloat[4]) { 1.0f, 1.0f, 1.0f, 1.0f});
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
    GLfloat p_coord[1][2] = { {-1000.0f, -1000.0f} }; //TODO: when to free?
    bov_points_param_t pParams = {
            .fillColor = {0.99f , 0.74f, 0.2f, 1.0f},
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
            { 1000.0,  0.0 }
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
            .fillColor = {0.99f , 0.74f, 0.2f, 0.0f},
            .outlineColor = {0.99f , 0.74f, 0.2f, 1.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.025f,
            .outlineWidth = 0.005f
    };
    // %%% --- RightNeigh and RightMost segments
    bov_points_param_t smsrParams = {
            .fillColor = {0.203f, 0.670f, 0.329f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t psmsrParams = {
            .fillColor = {0.203f, 0.670f, 0.329f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    // %%% --- LeftNeigh and LeftMost segments
    bov_points_param_t smslParams = {
            .fillColor = {0.839f, 0.176f, 0.125f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t psmslParams = {
            .fillColor = {0.839f, 0.176f, 0.125f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    // %%% --- RLN segments
    bov_points_param_t smsParams = {
            .fillColor = {0.376f, 0.047f, 0.749f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.005f,
            .outlineWidth = 0.00125f
    };
    bov_points_param_t psmsParams = {
            .fillColor = {0.376f, 0.047f, 0.749f, 1.0f},
            .outlineColor = {0.0f, 0.53f, 0.266f, 0.0f},
            .scale = {1.0f, 1.0f},
            .width = 0.015f,
            .outlineWidth = 0.005f
    };
    // %%% --- Textes
    GLfloat pixel64 = 2.0f / bov_window_get_yres(window) * 64.0f; //~64 pixels height
    bov_text_param_t textParams1 = {
            .outlineColor = { 1.0, 0.0, 0.0, 1.0 },
            .fillColor = {0.839f, 0.176f, 0.125f, 1.0f},
            .fontSize = bov_window_get_yres(window) / 30,
            .spaceType = PIXEL_SPACE,
            .pos = { bov_window_get_xres(window) * (1.0 / 60.0), bov_window_get_yres(window) * (1.0 - 2.0 / 30.0)  },
    };
    bov_text_param_t textParams2 = {
            .outlineColor = { 1.0, 0.0, 0.0, 1.0 },
            .fillColor = {0.739f, 0.076f, 0.025f, 1.0f},
            .fontSize = bov_window_get_yres(window) / 40,
            .spaceType = PIXEL_SPACE,
            .pos = { bov_window_get_xres(window) * (1.0 / 60.0), bov_window_get_yres(window) * (1.0 - 3.0 / 30.0)  },
    };
    bov_text_param_t textParams3 = {
            .outlineColor = { 0.0, 0.0, 0.0, 0.0 },
            .fillColor = {0.0f, 0.0f, 0.0f, 1.0f},
            .fontSize = bov_window_get_yres(window) / 40,
            .spaceType = PIXEL_SPACE,
            .pos = { bov_window_get_xres(window) * (1.0 / 60.0), bov_window_get_yres(window) * (1.0 - 4.0 / 30.0)  },
    };






    /*                                                   
        88  88b           d88         db           ,ad8888ba,   88888888888      
        88  888b         d888        d88b         d8"'    `"8b  88               
        88  88`8b       d8'88       d8'`8b       d8'            88               
        88  88 `8b     d8' 88      d8'  `8b      88             88aaaaa          
        88  88  `8b   d8'  88     d8YaaaaY8b     88      88888  88"""""          
        88  88   `8b d8'   88    d8""""""""8b    Y8,        88  88               
        88  88    `888'    88   d8'        `8b    Y8a.    .a88  88               
        88  88     `8'     88  d8'          `8b    `"Y88888P"   88888888888     
    */

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
                bov_points_set_color(intersection, bov_points_get_param(intersection).outlineColor);
                bov_points_set_outline_color(intersection, (GLfloat[4]) { 0.0, 0.0, 0.0, 0.0 });
                bov_points_set_outline_width(intersection, 0.005);
                bov_points_set_width(intersection, 0.01);
            }
            bov_points_draw(window, intersection, 0, data->Intersections->length);
            bov_points_delete(intersection);
            free(intersection_coord);

            // others
            bov_window_update(window);
        }
        freeDatastruct(data);
        freeList(segmentList);
        free(segment_coord);
        return EXIT_SUCCESS;
    }





    /*
               db         888b      88  88  88b           d88         db         888888888888  88    ,ad8888ba,    888b      88
              d88b        8888b     88  88  888b         d888        d88b             88       88   d8"'    `"8b   8888b     88
             d8'`8b       88 `8b    88  88  88`8b       d8'88       d8'`8b            88       88  d8'        `8b  88 `8b    88
            d8'  `8b      88  `8b   88  88  88 `8b     d8' 88      d8'  `8b           88       88  88          88  88  `8b   88
           d8YaaaaY8b     88   `8b  88  88  88  `8b   d8'  88     d8YaaaaY8b          88       88  88          88  88   `8b  88
          d8""""""""8b    88    `8b 88  88  88   `8b d8'   88    d8""""""""8b         88       88  Y8,        ,8P  88    `8b 88
         d8'        `8b   88     `8888  88  88    `888'    88   d8'        `8b        88       88   Y8a.    .a8P   88     `8888
        d8'          `8b  88      `888  88  88     `8'     88  d8'          `8b       88       88    `"Y8888Y"'    88      `888
    */

    if(animation && !image) {
        bool prevent_first_click = true;
        bool curr_click = false;
        bool finished = false;
        float iter_start_time = 0.0f;
        Point* last_p = createPoint(-730957.0, -137532384.0, NULL);

        // data container
        dataStruct *data = initDataStruct();
        if(data->p == NULL) { data->p = createPoint(0.0, -1000.0, NULL); }
        while (!bov_window_should_close(window)) {
            bov_lines_draw(window, segment, 0, nPoints);
            bov_points_draw(window, point, 0, nPoints);



            /*                                                       
                 .d88b.  d8b   db    .o88b. db      d888888b  .o88b. db   dD
                .8P  Y8. 888o  88   d8P  Y8 88        `88'   d8P  Y8 88 ,8P'
                88    88 88V8o 88   8P      88         88    8P      88,8P
                88    88 88 V8o88   8b      88         88    8b      88`8b
                `8b  d8' 88  V888   Y8b  d8 88booo.   .88.   Y8b  d8 88 `88.
                 `Y88P'  VP   V8P    `Y88P' Y88888P Y888888P  `Y88P' YP   YD
            */
            if (on_click) { // click event interception
                bov_text_t* text_indication = bov_text_new(
                        (GLubyte[]) {
                                "Left click to run the algorithm to the next point",
                        },
                        GL_STATIC_DRAW);
                bov_text_set_param(text_indication, textParams2);
                bov_text_draw(window, text_indication);
                bov_text_delete(text_indication);

                if ((window->clickTime[0] < -window->wtime + 0.025f && window->clickTime[0] > -window->wtime - 0.025f) && !prevent_first_click) {
                    curr_click = true;
                    printf("\n >>> click <<<\n");
                    if (! equalPoint(last_p, data->p)) {
                        free(last_p);
                        last_p = createPoint(data->p->x, data->p->y, data->p->U);
                        FindIntersections2(segmentList, data, data->p);

                    }
                    else {
                        finished = true;
                    }

                    p_coord[0][0] = (float) data->p->x;
                    p_coord[0][1] = (float) -data->p->y;

                }

                if (prevent_first_click) {
                    prevent_first_click = false;
                }


                /*
                     .d8b.  db    db d888888b  .d88b.  .88b  d88.  .d8b.  d888888b d88888b d8888b.
                    d8' `8b 88    88 `~~88~~' .8P  Y8. 88'YbdP`88 d8' `8b `~~88~~' 88'     88  `8D
                    88ooo88 88    88    88    88    88 88  88  88 88ooo88    88    88ooooo 88   88
                    88~~~88 88    88    88    88    88 88  88  88 88~~~88    88    88~~~~~ 88   88
                    88   88 88b  d88    88    `8b  d8' 88  88  88 88   88    88    88.     88  .8D
                    YP   YP ~Y8888P'    YP     `Y88P'  YP  YP  YP YP   YP    YP    Y88888P Y8888D'
                */
            } else {
                if (!equalPoint(last_p, data->p)) {
                    free(last_p);
                    last_p = createPoint(data->p->x, data->p->y, data->p->U);
                    FindIntersections2(segmentList, data, data->p);
                    if ((window->wtime - iter_start_time)/1000. < dt) {
                        sleep(dt - (window->wtime + iter_start_time)/1000.);
                    }
                    bov_text_t* text_indication = bov_text_new(
                            (GLubyte[]) {
                                    "\x91 Automatic play is on, no need to touch anything"

                            },
                            GL_STATIC_DRAW);
                    bov_text_set_param(text_indication, textParams2);
                    bov_text_draw(window, text_indication);
                    bov_text_delete(text_indication);
                }
                else {
                    bov_text_t* text_indication = bov_text_new(
                            (GLubyte[]) {
                                    "\x93 You reached the end of the set of segments !",
                            },
                            GL_STATIC_DRAW);
                    bov_text_set_param(text_indication, textParams2);
                    bov_text_draw(window, text_indication);
                    bov_text_delete(text_indication);
                }
                p_coord[0][0] = (float) data->p->x;
                p_coord[0][1] = (float) -data->p->y;
            }

            /*
                d888888b d8b   db    .d8b.  d8b   db db    db    .o88b.  .d8b.  .d8888. d88888b
                  `88'   888o  88   d8' `8b 888o  88 `8b  d8'   d8P  Y8 d8' `8b 88'  YP 88'
                   88    88V8o 88   88ooo88 88V8o 88  `8bd8'    8P      88ooo88 `8bo.   88ooooo
                   88    88 V8o88   88~~~88 88 V8o88    88      8b      88~~~88   `Y8b. 88~~~~~
                  .88.   88  V888   88   88 88  V888    88      Y8b  d8 88   88 db   8D 88.
                Y888888P VP   V8P   YP   YP VP   V8P    YP       `Y88P' YP   YP `8888Y' Y88888P
            */

            // draw text ! 
            bov_text_t* text_obj = bov_text_new(
                    (GLubyte[]) {
                            "SWEEPLINE ALGORITHM - press [h] for help",
                    },
                    GL_STATIC_DRAW);
            bov_text_set_param(text_obj, textParams1);
            bov_text_draw(window, text_obj);
            bov_text_delete(text_obj);

            if (finished) {
                bov_text_t* text_indication = bov_text_new(
                        (GLubyte[]) {
                                "You reached the end of the set of segments !",
                        },
                        GL_STATIC_DRAW);
                bov_text_set_param(text_indication, textParams3);
                bov_text_draw(window, text_indication);
                bov_text_delete(text_indication);
            }

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
                bov_points_t* psms = bov_points_new(sms_coord, sizeof(sms_coord), GL_DYNAMIC_DRAW);
                bov_points_set_param(psms, psmsParams);
                bov_points_draw(window, psms, 0, SMS->length);
                bov_points_delete(sms);
                bov_points_delete(psms);
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
                bov_points_set_param(psmsr, psmsrParams);
                bov_points_draw(window, psmsr, 0, SMSR->length);
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
                bov_points_t* psmsl = bov_points_new(smsl_coord, sizeof(smsl_coord), GL_DYNAMIC_DRAW);
                bov_points_set_param(psmsl, psmslParams);
                bov_points_draw(window, psmsl, 0, SMSL->length);
                bov_points_delete(smsl);
                bov_points_delete(psmsl);
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
        }
    }


    return EXIT_SUCCESS;
}

