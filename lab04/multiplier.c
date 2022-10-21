#include <superkarel.h>

void turn_right();
void double_row();
void double_all();
void move_up();
void find_south_west_corner();
int main(){
    turn_on("multiplier.kw");
    set_step_delay(200);
    find_south_west_corner();
    while(front_is_clear()){
        double_row();
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

void double_all(){
    pick_beeper();
    if(beepers_present()){
        double_all();
    }
    put_beeper();
    put_beeper();
}

void double_row(){
    while(front_is_clear()){
        if(beepers_present()){
            double_all();
        }
        step();
    }
    if(beepers_present()){
        double_all();
    }
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
