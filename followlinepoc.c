void forwards_pid_mihir(int side, double target, double position, int speed)
{
    double current = analog(0);
    double error = target - current;
    double last_error;
    double integral;
    double integration;
    double derivative;
    double derivation;
    double proportional;
    double powerup;
    double powerdown;
    double correction;
    int counter=0;
    cmpc(LEFTWHEEL);

    if(side == 1)		//RIGHTSIDE
    {
        while(gmpc(LEFTWHEEL) < position)
        {
            current = analog(0);
            error = target - current;
            integral=integral+error;
            //Sum of all errors(integral) should approach zero.
            //If integral is mostly positive then you are mostly on white and straying to the left
            //If integral is mostly negative then you are mostly on black and straying to the right
            integration=Ki*integral;
            //Ki is some arbitrary value, Ki should most likely be lower than Kd and Kp
            proportional = Kp * error;
            //increasing Kp makes it more drastic decreasing it makes it smoother
            
            if(counter!=0){
            derivative=last_error-error;
            derivation=Kd * derivative;
            correction = proportional + integration + derivation;
        	 }
        	else{
        	correction = proportional
          printf("\t ONLY USING PROPORTIONAL");
        	}
          if(error<0){
            integration=abs(integration)*-1
            integration=abs(derivation)*-1
            }
          
            printf("proportional: %lf   integration: %lf  derivation: %lf\n",proportional,integration,derivation);
            powerup = speed + correction;
            powerdown = speed - correction;
            printf("powerup: %lf\n",powerup);
            printf("powerdown: %lf\n",powerdown);
            mrp(LEFTWHEEL,powerdown, 4);							
            mrp(RIGHTWHEEL,powerup, 4);
            //printf("%i , %lfa , %lfb , %lfc , %i,  %lfa + %lfb + %lfc",counter,error, integral, derivative,counter,error, integral, derivative);
            //use to figure out defines by pasting list in excel and the pasting that in desmos.Use slider to adjust values till graph matches sin(x)/x
            last_error=error;
            counter=counter+1
        }
    }
