#include <iostream>
#include <string>
using namespace std;

struct fridge{
    int milk = 0 ;
    int meat = 0;
    int cheese = 0;
    int bonbons = 0;
};
void status(fridge& box){
    cout<<"milk: "<<box.milk<<'\n';
    cout<<"meat: "<<box.meat<<'\n';
    cout<<"cheese: "<<box.cheese<<'\n';
    cout<<"bonbons: "<<box.bonbons<<'\n';
}
void options(){
    cout<<"Choose option\n";
    cout<<"add \"product\" \"massa\""<<'\n';
    cout<<"delete \"product\" \"massa\""<<'\n';
}
void work(fridge& box){
        status(box);
        options();
        int k;
        int massa = 0;
        string operation, food;
        cin>>operation>>food>>massa;
        if (operation == "add"){
            k = 1;
        } else {
            k = -1;
        }
        if (food == "milk"){
            box.milk += k*massa;
        }
        if (food == "meat"){
            box.meat += k*massa;
        }
        if (food == "cheese"){
            box.cheese += k*massa;
        }
        if (food == "bonbons"){
            box.bonbons += k*massa;
        }
        status(box);
}
int main()
{
    fridge box1;
    fridge box2;
    while (true){
        string user_choose = "";
        cout<<"Choose fridge: print \"box1\" or \"box2\""<<'\n';
        cout<<"If you want to exit, print \"exit\""<<'\n';
        cin>>user_choose;
        if (user_choose == "box1"){
            work(box1);
        } else if (user_choose == "box2"){
            work(box2);
        } else {
            return 0;
        }
    }
    return 0;
}
