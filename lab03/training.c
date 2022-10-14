#include <superkarel.h>

void jump_over();
void turn_right();
int main(){
    turn_on("training.kw");
    set_step_delay(300);
    while(beepers_present() == false){
        jump_over();
    }

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void jump_over(){
    turn_left();
    step();
    turn_right();
    step();
    turn_right();
    step();
    turn_left();
}
