#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Random rank in PUBG
char *chooseRandomwords(){
    char *words[]= {"Silver", "Gold ", "Platinum ", "Diamond","Crown", "Ace ", "Conqueror"};
 //   int totalWords= sizeof(words)/sizeof(words[0]);
   // int size= sizeof(words); // so this is 28
     int size = sizeof(words[0]);
  //  printf("%d\n", totalWords);
    printf("%d ",size );
    srand((unsigned int)time(NULL));
//    int randomIndex= rand() %totalWords;
//    return words[randomIndex];
}


int main(){
    char*Randomwords= chooseRandomwords();
   // printf("Random words :%s",Randomwords);
    
    return 0;
}