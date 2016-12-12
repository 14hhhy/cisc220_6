#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int p1,p2,p3,p4,p5 = 0; //car positions starting at 0

//creates and modifies the lanes
void dispCar(int pNum, int carNum) {
char s1[] = "~";
char s2[] = "|->";
char s3[] = " ";
char car[41];
strcpy(car,"");
if (pNum>0) {
for (int i=0; i<pNum; i++) { //if car has moved
strcat(car,s1);}}
strcat(car,s2);
for (int j=40-pNum; j>0; j--) {
strcat(car,s3);}
printf("%s# Lane %d #\n",car,carNum);}

//displays the starting message and the lanes
void dispCars() {
system("clear");
printf("Welcome to CISC220 Racing Arena\nHit Enter to move forward\n\n");
dispCar(p1,1);
dispCar(p2,2);
dispCar(p3,3);
dispCar(p4,4);
dispCar(p5,5);}

//car1 thread
void *carOne() {
char input[2];
while (1) {
fgets(input,sizeof(input),stdin);
if (input[0]=='\n') { //if use inputs ENTER
p1++;}}}

//car2 thread
void *carTwo() {
for (int i=0; i<40; i++) {
p2++;
usleep(rand()%100001);}} //sleep for 0-100001 microseconds (0-100 milliseconds)

//car3 thread
void *carThree() {
for (int i=0; i<40; i++) {
p3++;
usleep(rand()%100001);}}

//car4 thread
void *carFour() {
for (int i=0; i<40; i++) {
p4++;
usleep(rand()%100001);}}

//car 5 thread
void *carFive() {
for (int i=0; i<40; i++) {
p5++;
usleep(rand()%100001);}}

//refreshes screen
void *draw() {
while (p1!=40 && p2!= 40 && p3!=40 && p4!=40 && p5!=40) {
dispCars();
usleep(20000);}} //sleep for 20000 microseconds (20 milliseconds)

int main() {
dispCars(); //display initial screen
char input[2];
while (input[0]!='\n') { //waits for ENTER to be hit to start threads
fgets(input,sizeof(input),stdin);} //waits for user input
pthread_t thread0,thread1,thread2,thread3,thread4,thread5;
pthread_create(&thread1, NULL, carOne, NULL);
pthread_create(&thread2, NULL, carTwo, NULL);
pthread_create(&thread3, NULL, carThree, NULL);
pthread_create(&thread4, NULL, carFour, NULL);
pthread_create(&thread5, NULL, carFive, NULL);
pthread_create(&thread0, NULL, draw, NULL);
pthread_join(thread0, NULL); //waits for draw thread to finish
dispCars();
int win; //winning lane
if (p1==40) {
win = 1;
} else if (p2==40) {
win = 2;
} else if (p3==40) {
win = 3;
} else if (p4==40) {
win = 4;
} else if (p5==40) {
win = 5;}
printf("\nPlayer %d WINS\n\n",win); // displays winning lane
return 0;}
