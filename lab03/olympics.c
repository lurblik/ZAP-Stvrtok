#include <superkarel.h>

void jump_over();
void turn_right();
int main(){
    turn_on("olympics5.kw");
    set_step_delay(300);
    while(beepers_present() == false){
        if(front_is_blocked()){
            jump_over();
        } else {
            step();
        }
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
    while(right_is_blocked()){
        step();
    }
    turn_right();
    do {
        step();
    }while(right_is_blocked());
    turn_right();
    while(front_is_clear()){
        step();
    }
    turn_left();
}
