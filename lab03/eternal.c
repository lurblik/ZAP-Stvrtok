#include <karel.h>

void turn_around();
int main(){
    turn_on("empty.kw");
    set_step_delay(200);
    while(facing_north() == false){
        turn_left();
    }
    while(true){
        if(front_is_clear()){
            step();
        } else {
            turn_around();
        }
    }
    turn_off();
    return 0;
}

void turn_around(){
    turn_left();
    turn_left();
}
