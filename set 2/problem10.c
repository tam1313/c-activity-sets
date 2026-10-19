#include <stdio.h>
struct batting_record{
    char name[100];
    int runs, balls, minutes, fours, sixers;
    float strike_rate;
};
typedef struct batting_record Batting_record;
void input_player(Batting_record *player){
    printf("Enter name funs balls minutes fours sixers\n");
    scanf("%s%d%d%d%d%d",player->name, &player->runs,&player->balls,&player->minutes,&player->fours,&player->sixers);
   
}
void input_all_players(int n, Batting_record players[n]){
    for(int i=0;i<n;i++) {
        input_player(&players[i]);
    }
}
void compute_strike_rate(Batting_record *player){
    player->strike_rate = player->runs * 100.0/player->balls;
}
void compute_strike_rates(int n, Batting_record players[n]){
    for(int i=0;i<n;i++) {
        compute_strike_rate(&players[i]);
    }
}
void display_player(Batting_record player){
    printf("%s %d %d %d %d %d %f\n",player.name, player.runs,player.balls,player.minutes,player.fours,player.sixers,player.strike_rate);        
}
void display_players(int n, Batting_record players[n])
{
    printf("Batting record of players:\n");
    for(int i=0;i<n;i++) {
        display_player(players[i]);
    }
}
int main() {
    int n;
    printf("Enter no of players: ");
    scanf("%d",&n);
    Batting_record players[n];
    input_all_players(n,players);
    compute_strike_rates(n,players);
    display_players(n,players);
    return 0;
}