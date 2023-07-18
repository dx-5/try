#include "app.h"
#include "Watch.h"
#include <stdio.h>
#include <unistd.h>

/* メインタスク(起動時にのみ関数コールされる) */
void main_task(intptr_t unused) {

    /* センサー入力ポートの設定 */
    ev3_sensor_config(touch_sensor ,TOUCH_SENSOR);
    ev3_sensor_config(color_sensor ,COLOR_SENSOR);
    ev3_sensor_config(sonar_sensor ,ULTRASONIC_SENSOR);
    ev3_sensor_config(gyro_sensor  ,GYRO_SENSOR);
    
    /* モーター出力ポートの設定 */
    ev3_motor_config(arm_motor     ,LARGE_MOTOR);
    ev3_motor_config(left_motor    ,MEDIUM_MOTOR);
    ev3_motor_config(right_motor   ,MEDIUM_MOTOR);
    
    printf("Start Line Trace!!\n");
    
    /* define watch object */
    Watch watch;

    /* initialize watch object */
    watch.init();
    
    /* ライントレースタスクの起動 */
    while(1){
        watch.getRawColor();
        watch.rgb2Hsv();
        watch.checkWhite();
        watch.checkBlack();
        watch.rgb2gray();
        watch.checkBlue();
        watch.checkRed();
        watch.checkGreen();
        //printf("white:%d r:%d g:%d b:%d s:%f\n",watch.iflag_white,watch.ival_red,watch.ival_green,watch.ival_blue,watch.val_s1);
        
        //printf("hue = %f\n",watch.val_h);
        //printf("saturation = %f\n",watch.val_s1);
        //printf("brightness= %f\n",watch.val_v);
        printf("grayscale = %f\n",watch.grayscale);
        
        if (watch.iflag_white == true){
            printf("detected white\n");
            //break;
        }
        if (watch.iflag_black == true){
            printf("detected black\n");
            //break;
        }
        if (watch.iflag_green == true){
            printf("detected green\n");
            //break;
        }
        if (watch.iflag_blue == true){
            printf("detected blue\n");
            //break;
        }
        sleep(5);
    }

    /* タスク終了 */
    //ext_tsk();
}
