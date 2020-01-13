#include <stdio.h>
void fizzbuzzer()
{
    // Implement this function according to ../readme.txt
    for(int i=1; i<=100; i++)
    {
        if(i%3==0 && i%5==0){
            //FizzBuz
            printf("FizzBuzz\n");
        }else if(i%3==0){
            //Fiz
            printf("Fizz\n");
        }else if(i%5 == 0){
            //Buz
            printf("Buzz\n");
        }else{
            //print number
            printf("%d\n",i);
        }
    }
}

int main(void)
{
    fizzbuzzer();
    return 0;
}
