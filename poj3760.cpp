#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const std :: string soilder_name[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
const int red_produce_order[5] = {3,4,5,2,1};                 
const int blue_produce_order[5] = {4,1,2,3,5};                
                                        
int CASE,N,M,T;                                                        
int soilder_life[4], soilder_acty[4],soilder_cost[4];             
int total_time,time[5];                                           //time : this array has four room to record time as 0 0 0 : 00;
                                                                  
int red_produce_num,blue_produce_num;                             //record the total num of soilders of each camp that have been produced
int total_soilder_num;                                            //record the total num of that have been produced
                                                                  
struct Soilder {                                                                                                     
    int type, life, acty;                                               
    bool belong, alive;                                                  //belong : red = 0, bule = 1; 
    int pos, num,special_judge;                                                                                                       
    
    Soilder(){};         
                                                                 
    Soilder(int x,bool y) {                                       
        type = x;                                                 
        life = soilder_life[x], acty = soilder_acty[x];           
        belong = y;                                             
        if(belong) pos = N + 1;                                   
        else pos = 0;                                             
        alive = 1;     
        special_judge = 0;                                           
    }                                                             
                                                                  
} soilder[80];                                                    
                                                                  
struct City {                                                     
    int m;                                                        
    int belong;                                                   //belong : 0 = unsigned, 1 = red, 2 = bule
    int fight_count;                                              //fight_count : record the num of the fight that happened there
    int fight_result[40];                                         //fight_result : 0 = noresult, 1 = red, 2 = bule
    int soilder_there_num; 
    int soilder_there[40];                                        //soilder_there : record the soilders that stay here
    int soilder_rom[40];                                          //record the soilder that will leave or get here
                                                                  
    City() {                                                     
        m = 0;                                                    
        belong = 0;                                              
        fight_count = 0;    
        soilder_there_num = 0;                                      
        memset(fight_result,0,sizeof(fight_result));     
        memset(soilder_there,0,sizeof(soilder_there)); 
        memset(soilder_rom,0,sizeof(soilder_rom));                   
    }                                                             
                                                                  
} city[25];                                                       
 


void init() {                                                                 //complite accept 
    std :: cin >> M >> N >> T;                                    
    for(int i = 0;i < 5;i ++) std :: cin >> soilder_life[i];      
    for(int i = 0;i < 5;i ++) std :: cin >> soilder_acty[i];      
    for(int i = 0;i < 5;i ++) soilder_cost[i] = soilder_life[i];  
                                                                  
    city[0].m = city[N + 1].m = M;                              
    city[0].belong = 1; city[N + 1].belong = 2;                   
                                                            
    total_time = 0;
    //time[1] = time[2] = time[3] = time[4] = time[5] = 0;                        
    memset(time,0,sizeof(time));
    red_produce_num = blue_produce_num = 1;
    total_soilder_num = 0;                                
}                                                                 
                                                                  
inline void time_run() {                                                      //accept      
    total_time += 10;                                             
    time[4] += 10;                                                
    if(time[4] == 60) time[4] = 0,time[3] ++;                     
    if(time[3] == 10) time[3] = 0,time[2] ++;                     
}                                                                 
                                                                  
inline void time_print() {                                                    //accept 
    std :: cout << time[1] << time[2] << time[3] << ":";          
    if(time[4]) std :: cout << time[4] << " ";                   
    else std :: cout << "00 ";                                    
}                                                                 
                                                                  
inline void soilder_produce() {                                               //accept 

    int type = red_produce_order[(red_produce_num % 5 - 1 < 0) ? 4 : red_produce_num % 5 - 1 ] - 1;    //red camp produce
//  std :: cout << type << "\n"; 
    if(city[0].m >= soilder_cost[type]) {    

        city[0].m -= soilder_cost[type];     

        soilder[++total_soilder_num] = Soilder(type, false);    

        soilder[total_soilder_num].num = red_produce_num; 

        red_produce_num ++;    

        time_print();

        std :: cout << "red " << soilder_name[type] << " " << soilder[total_soilder_num].num << " born\n";
    }    

    type = blue_produce_order[(blue_produce_num % 5 - 1 < 0) ? 4 : blue_produce_num % 5 - 1 ] - 1;      //blue camp produce
//  std :: cout << type << "\n"; 
    if(city[N + 1].m >= soilder_cost[type]) {    

        city[N + 1].m -= soilder_cost[type];     

        soilder[++total_soilder_num] = Soilder(type, true);    

        soilder[total_soilder_num].num = blue_produce_num; 

        blue_produce_num ++;    

        time_print();

        std :: cout << "blue " << soilder_name[type] << " " << soilder[total_soilder_num].num << " born\n";
    }                   
//  std :: cout << red_produce_num << " " << blue_produce_num << "\n"; 
}                                                                 
                                                                
inline void soilder_move() {               
    //remember to add the special judge for icemans' movement
    
}

inline void city_produce() {                                                  //accept
    for(int i = 1; i <= N; i ++) 
        city[i].m += 10;
}

inline void soilder_delivery() {
    for(int i = 1; i <= N;i ++) {
        if(city[i].soilder_there_num == 1) {
            int code = city[i].soilder_there[1];
            if(!soilder[code].belong) {                     //red camp get the elements
                city[0].m += city[i].m;
                time_print();
                std :: cout << "red " << soilder_name[soilder[code].type] << " " << soilder[code].num;
                std :: cout << " earned " << city[i].m << " elements for his headquarter\n";               
                city[i].m = 0;
            }
            else {
                city[N + 1].m += city[i].m;
                time_print();
                std :: cout << "blue " << soilder_name[soilder[code].type] << " " << soilder[code].num;
                std :: cout << " earned " << city[i].m << " elements for his headquarter\n"; 
                city[i].m = 0;
            }
        }
    }
} 

inline void element_turned(int from, int to, int delt) {
    if(soilder[from].type == 3)
        soilder[to].life += delt;
}

inline void cheer(int s, int pos) {
    if(!soilder[s].type && soilder[s].alive) {
        time_print();
        if(!soilder[s].belong) std :: cout << "red ";
        else std :: cout << "blue ";
        std :: cout << soilder_name[soilder[s].type] << " " << soilder[s].num << " yelled in city " << pos << std :: endl;
    }
}

inline void prize(int s) {
    if(!soilder[s].belong) {
        if(city[0].m >= 8)
            soilder[s].life += 8, city[0].m -= 8;
    }
    else if(city[N + 1].m >= 8)
        soilder[s].life += 8, city[N + 1].m -= 8;
}

inline void city_belong_judge(int pos) {
    for(int i = 2;i <= n;i ++) {
        if(city[pos].fight_result[i] == city[pos].fight_result[i - 1]) {
            city[pos].belong = city[pos].fight_result[i];
            break;
        } 
    }
}

inline void attack(int sa, int sb, int pos) {

    int rom = soilder[sb].life;

    if(soilder[sa].acty >= soilder[sb].life) {            //if soilder_a can kill so
        soilder[sb].life = 0;
        soilder[sb].alive = 0;
        time_print();
        if(!soilder[sb].belong) std :: cout << "red ";
        else std :: cout << "blue ";
        std :: cout << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " was killed in city " << pos << std :: endl; 
        
        if(!soilder[sa].belong) {                                  //record the result of the fight
            city[pos].fight_result[++fight_count] = 0;
        }
        else city[pos].fight_result[++fight_count] = 1;
        if(city[pos].fight_count > 1) city_belong_judge(pos);      //update the camp the city belongs to

        if(solider[sa].type == 4) {                        //the life and the activity of a wolf winner will be double
            solider[sa].special_judge ++;
            if(solider[sa].special_judge == 2) {
                soilder[sa].life *= 2;
                soilder[sa].acty *= 2;
                solider[sa].special_judge = 0;
            }
        }

        element_turned(sb, sa, rom);

        prize(sa);                                          //give the solider a prize for his kill
    }
    else soilder[sb].life -= soilder[sa].acty;

     /*
        dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，就会欢呼。 
        ninja 挨打了也从不反击敌人。 
        iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。
        即iceman不会因走多了而死。 
        lion 若是战死，则其战斗前的生命值就会转移到对手身上。 
        在一个 wolf 通过主动攻击杀死敌人的次数达到偶数的时刻（次数从1开始算），在战斗完成后，该 wolf 生命值和攻击力都增加1倍。如果
        其杀死的敌人是lion,则攻击力和生命值先加倍，然后才吸取lion的生命值。获取总部的生命元奖励，发生在加倍之后。只有在主动攻击杀死敌人
        时才能有加倍的事情，反击杀死敌人则不不会发生加倍。 
    */
    if(soilder[sb].type != 2 && soilder[sb].alive) { //反击
        time_print();                                       //事件输出
        if(!soilder[sb].belong) std :: cout << "red ";
        else std :: cout << "blue ";
        std :: cout << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " fought back against ";
        if(!soilder[sa].belong) std :: cout << "red ";
        else std :: cout << "blue ";
        std :: cout << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " in city " << pos << std :: endl;

        if(soilder[sb].acty >= soilder[sa].life) {          //伤害判断

            rom = solider[sa].life;

            soilder[sa].life = 0;
            soilder[sa].alive = 0;
            time_print();
            if(!soilder[sa].belong) std :: cout << "red ";
            else std :: cout << "blue ";
            std :: cout << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " was killed in city " << pos << std :: endl; 


            if(!soilder[sb].belong) {                                  //record the result of the fight
                city[pos].fight_result[++fight_count] = 0;
            }
            else city[pos].fight_result[++fight_count] = 1;
            if(city[pos].fight_count > 1) city_belong_judge(pos);      //update the camp the city belongs to

            element_turned(sa, sb, rom);

            prize(sb);                                                 //give the solider b prize for his kill
        }
        else soilder[sa].life -= soilder[sb].acty;
    }
    cheer(sa, pos);    cheer(sb, pos);
}

inline void fight(int sa, int sb, int pos) {
    time_print();
    if(!city[pos].belong) {
        if(!pos % 2) {               //在编号为偶数的无旗城市，由蓝武士主动进攻
            if(soilder[sa].belong) {
                attack(sa, sb, pos);
                std :: cout << "blue " << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " attack ";
                std :: cout << "red" << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " in city ";
                std :: cout << pos << " with " << soilder[sa].life << " elements and force " << soilder[sa].acty << "\n";
            }
            else {
                attack(sb, sa, pos);
                std :: cout << "red " << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " attack ";
                std :: cout << "blue" << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " in city ";
                std :: cout << pos << " with " << soilder[sb].life << " elements and force " << soilder[sb].acty << "\n";
            }
        }
        else {                     //在编号为奇数的无旗城市，由红武士主动进攻
            if(soilder[sa].belong) {
                attack(sb, sa, pos);
                std :: cout << "red " << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " attack ";
                std :: cout << "blue" << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " in city ";
                std :: cout << pos << " with " << soilder[sb].life << " elements and force " << soilder[sb].acty << "\n";
            }
            else {
                attack(sa, sb, pos);
                std :: cout << "blue " << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " attack ";
                std :: cout << "red" << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " in city ";
                std :: cout << pos << " with " << soilder[sa].life << " elements and force " << soilder[sa].acty << "\n";
            }
        }
    }
    else {
        if(city[pos].belong == 1) {                   //在红方城市，由红武士主动发起进攻
            if(!soilder[sa].belong) {
                attack(sa, sb, pos);
                std :: cout << "red " << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " attack ";
                std :: cout << "blue" << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " in city ";
                std :: cout << pos << " with " << soilder[sa].life << " elements and force " << soilder[sa].acty << "\n";
            }          
            else {
                attack(sb, sa, pos);
                std :: cout << "blue " << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " attack ";
                std :: cout << "red" << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " in city ";
                std :: cout << pos << " with " << soilder[sb].life << " elements and force " << soilder[sb].acty << "\n";
        }
        else {                                        //在蓝方城市，由蓝武士主动进攻
            if(soilder[sa].belong) {
                attack(sa, sb, pos);
                std :: cout << "blue " << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " attack ";
                std :: cout << "red" << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " in city ";
                std :: cout << pos << " with " << soilder[sa].life << " elements and force " << soilder[sa].acty << "\n";
            };
            else {
                attack(sb, sa, pos);
                std :: cout << "red " << soilder_name[soilder[sb].type] << " " << soilder[sb].num << " attack ";
                std :: cout << "blue" << soilder_name[soilder[sa].type] << " " << soilder[sa].num << " in city ";
                std :: cout << pos << " with " << soilder[sb].life << " elements and force " << soilder[sb].acty << "\n";
            }
        }
    }
}

inline void fight_judge() {
    for(int i = 1;i <= N;i ++) {
        if(soilder_there == 2) {
            int a = soilder_there[1], b = soilder_there[2];
            fight(a,b,i);
        }
     }
}

inline void report() {                                                        //accept
    time_print();
    std :: cout << city[0].m << " elements in red headquarter\n";
    
    time_print();
    std :: cout << city[N + 1].m << " elements in blue headquarter\n";
}

inline void make_things() {                                                   //accept
    time_run(); 
    if(!time[4]) soilder_produce();
    else if(time[4] == 10) soilder_move();
    else if(time[4] == 20) city_produce();
    else if(time[4] == 30) soilder_delivery();
    else if(time[4] == 40) fight_judge();
    else report();
}



int main() {
    std :: cin >> CASE;
    for(int c = 1; c <= CASE; c ++) {
        std :: cout << "Case:" << c << "\n";
        init();
        soilder_produce();
        while(total_time < T)
            make_things();
    }
    for(int i = 1;i <= 5;i ++) {
        std :: cout << i << " " << soilder[i].num << " " << soilder_name[soilder[i].type];
        std :: cout << "\nbelong : " << soilder[i].belong << " " << soilder[i].pos << "\n";  
    } 
}