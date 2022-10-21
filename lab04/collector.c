#include <superkarel.h>

void turn_right();
void pick_row();
void pick_all();
void move_up();
void find_south_west_corner();
int main(){
    turn_on("collector2.kw");
    set_step_delay(200);
    find_south_west_corner();
    while(front_is_clear()){
        pick_row();
        move_up();
    }
    turn_off();
    return 0;
}

void turn_right(){
    set_step_delay(0);
    turn_left();
    turn_left();
    set_step_delay(200);
    turn_left();
}

void pick_all(){
    while(beepers_present()){
        pick_beeper();
    }
}

void pick_row(){
    while(front_is_clear()){
        pick_all();
        step();
    }
    pick_all();
}

void move_up(){
    if(facing_east()){
        turn_left();
    } else {
        turn_right();
    }
    if(front_is_clear()){
        step();
        if(right_is_blocked()){
            turn_left();
        } else {
            turn_right();
        }
    }
}

void find_south_west_corner(){
    while(not_facing_west()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
    turn_left();
    while(front_is_clear()){
        step();
    }
    turn_left();
}
