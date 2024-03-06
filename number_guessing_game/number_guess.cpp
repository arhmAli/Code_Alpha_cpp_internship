#include <iostream>
#include <random>
#include <vector>
using namespace std;

class numberGuess{
    private:
    int randInd;
    int randNum;
    int guessed;
    int diff;
    public:
    int rndm(int i){
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution <int> dis(1,100);
    // int random_num=dis(gen);
    // return random_num;
    randInd=i;
    vector <int> arr={7,28,44,55,78,62};
    return arr[randInd];
}

void checkGuess(int num, int random_num){
    randNum=random_num;
    guessed=num;
    diff=randNum-guessed;
    // cout<<diff<<endl;
    if(diff > 50 && diff < 100){
        cout<<"Your guess is too far"<<endl;
    }
    else if(diff > 30 && diff < 50){
        cout<<"Your guess is almost near"<<endl;
    }
    else if(diff > 10 && diff < 30){
        cout<<"Your guess is near"<<endl;
    }
    else if(diff > 3 && diff < 10){
        cout<<"Your guess is very very near"<<endl;
    }
    else if(diff==0){
        cout<<"Your guess is correct the random number was "<<random_num<<endl;
    }
    else{
        cout<<"The difference is now negative"<<endl;
    }
}

};
int main(){
    numberGuess game;
    cout<<"*****----CHOOSE LEVEL OF DIFFICULTY FROM 0-5----*****"<<endl;
    int num;
    cin>>num;
    int randomNum=game.rndm(num);
    int myNum;
    cout<<"Enter a number"<<endl;
    cin>>myNum;
    while(true){
        game.checkGuess(randomNum,myNum);
        if(randomNum==myNum){
            break;
        }
        cout<<"Enter a number"<<endl;
        cin>>myNum;
    }
}
