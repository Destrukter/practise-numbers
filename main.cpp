//Practise_Numbers
//Frederik Hinz
//05.01.2021

#include <iostream>

using namespace std;

int main()
{
    while(true){
        short task = 0;
        cout<<"Which task do you want to start? (0 for help)"<<endl;                                //User is asked which task he wants to start
        cin>>task;
        if(5==task){                                                                                    //Task 5 is started (breaking down a custom number)
            system("clear");
            cout<<"Task 5:"<<endl;
            short number = 0;
            short numbersafe = 0;
            short thousands = 0;
            short hundreds = 0;
            short tens = 0;
            short ones = 0;
            short counter = 13;
            bool binary[14] = {0};
            while(true){                                                                                        //Until valid number is entered the user keeps getting asked to enter a number
                cout<<"Please enter a positive number with a maximum of four digits:"<<endl;
                cin>>number;
                if(number>=10000 || number<0){
                   cout<<"Number has more than four digits or is negative!"<<endl;
                   cin.clear();
                   cin.ignore();
                }
                else{
                    break;
                }
            }
            numbersafe = number;                                                                                //Entered number is safed in another var for later
            while(number>999){                                                                                  //Test how many 1000 do fit in number and answer is safed in var thousands
                number -= 1000;
                thousands++;
            }
            while(number>99){                                                                                   //Test how many 100 do fit in the rest and answer is safed in var hundreds
                number -= 100;
                hundreds++;
            }
            while(number>9){                                                                                    //Test how many 10 do fit in the rest and answer is safed in var tens
                number -= 10;
                tens++;
            }
            while(number>0){                                                                                    //Test how many 1 do fit in the rest and answer is safed in var ones
                number -= 1;
                ones++;
            }
            cout<<"Your number contains of:"<<endl<<thousands<<" thousands"<<endl<<hundreds<<" hundreds"<<endl<<tens<<" tens"<<endl<<ones<<" ones"<<endl;   //Result of previous calculation is printed out
            number = numbersafe;                                                                                //Number is set to the original number that was entered for upcoming calculation
            while(-1!=counter){                                                                                 //Binary number is calculated and digits are safed in array(backwards counter=13)
                binary[counter] = number%2;                                                                     //Max number 9999 so max digits for binary is 14 -> loop is repeated 14 times
                number /= 2;
                counter--;
            }
            counter = 0;
            cout<<"Your number in binary: ";
            while(14!=counter){                                                                                 //Digits safed in array are printed out(forwards counter=0)
                if(0==binary[counter]){                                                                         //Until first Digit is 1 nothing is printed out because every 0 before that is insignificant
                   counter++;
                   if(14==counter){                                                                             //If number is 0 nothing is printed out so if last digit is still 0 a 0 is printed out
                       cout<<"0";
                   }
                }
                else{
                    while(14 != counter){
                        cout<<binary[counter];
                        counter++;
                    }
                }
            }
            cout<<endl;
        }
        else if(6==task){                                                                               //Task 6 is started (Playing with Numbers)
            system("clear");
            cout<<"Task 6:"<<endl;
            short number = 0;
            short counter = 0;
            while(number!=101){                                                                                 //Every number between 1 and 100 is being tested(If one of the tests is true number is printed out)
                if(1==number%2 && 11==number/counter && 0==number%counter){                                     //If it has the same digit two times and is odd at the same time
                    cout<<number<<" ";
                    }
                if(41>number && 27<number && 0==number%2){                                                      //If it is between 21 and 27 and isnt odd at the same time
                    cout<<number<<" ";
                }
                counter++;
                number++;
                if(10==counter){
                    counter -= 10;
                }
            }
            cout<<endl;
        }
        else if(7==task){                                                                               //Task 7 is started (Minesweeper)
            system("clear");
            cout<<"Task 7:"<<endl;
            char field[50];
            short counter = 0;
            short mine[3];
            short column = 0;
            short row = 0;
            short round = 0;
            bool surrender = 0;
            while(50 != counter){                                                                               //Field is being filled with *
                field[counter] = '*';
                counter++;
            }
            mine[0] = rand() % 49;                                                                              //Position of 1st mine is set
            mine[1] = rand() % 49;
            while (mine[1]==mine[0]){                                                                           //Position of 2nd mine is set(until its different)
                mine[1] = rand() % 49;
            }
            mine[2] = rand() % 49;                                                                              //Position of the 3rd mine is set(until its different)
            while (mine[2]==mine[1]){
                mine[2] = rand() % 49;
            }
            while(0==surrender){                                                                                //Game loop(until mine is hit or user surrenders)
                system("clear");                                                                                    //Previous field is deleted
                counter = 0;
                while(50!=counter){                                                                                 //Field is printed out
                    cout<<field[counter];
                    if(0==(counter+1)%10){
                        cout<<endl;
                    }
                    counter++;
                }
                do{
                    cout<<"Which row do you want to uncover?(1-5 | 0 to surrender)";                                //User is asked to select row of the position he wants to uncover until he submits a possible number
                    cin>>row;
                    cout<<endl;
                    while(row<0 || row>5){
                        cout<<"You have to submit a number between 1 and 5!"<<endl<<"Which row do you want to uncover?(1-5 | 0 to surrender)";
                        cin>>row;
                        cout<<endl;
                    }
                    if(0==row){                                                                                     //Position selection is ended because of surrender
                        surrender = 1;
                        break;
                    }
                    cout<<"Which column do you want to uncover?(1-10)";                                             //User is asked to select column of the position he wants to uncover to uncover until he submits a possible number
                    cin>>column;
                    cout<<endl;
                    while(column<0 || column>10){
                        cout<<"You have to submit a number between 1 and 10!"<<endl<<"Which column do you want to uncover?(1-10)";
                        cin>>column;
                        cout<<endl;
                    }
                    if(0==column){                                                                                  //Position selection is ended because of surrender
                        surrender = 1;
                        break;
                    }
                    column--;
                    row--;
                }
                while('X'==field[row*10+column]);                                                               //Do-while-loop until user selected a position that wasnt selected before
                if(1==surrender){                                                                               //Check if user gave up if so game loop is ended
                    break;
                }
                if(row*10+column!=mine[0] && row*10+column!=mine[1] && row*10+column!=mine[2]){                 //Position selected by the user is safed in field with X and its checked if mine was hit if not round counter goes up by one
                    field[row*10+column] = 'X';
                    round++;
                }
                else {                                                                                          //Game loop is ended because mine was hit, position of mine is safed in field with O
                    field[row*10+column] = 'O';
                    break;
                }
            }
            while(50!=counter){                                                                                 //Field is printed out one last time(wasnt printed out before because game loop ended)
                cout<<field[counter];
                if(0==(counter+1)%10){
                    cout<<endl;
                }
                counter++;
            }
            if(1==round){                                                                                       //Number of survived rounds is printed out if game loop ended(with correct grammar)
            cout<<"You survived "<<round<<" Round!"<<endl;
            }
            else{
            cout<<"You survived "<<round<<" Rounds!"<<endl;
            }
        }
        else if(8==task){                                                                               //Task 8 is started(number list creation)
            system("clear");
            cout<<"Task 8:"<<endl;
            int current = 0;
            float sum = 0;
            int max = 0;
            while(true){                                                                                        //User is getting asked to set a total amount of numbers(has to be positive) he wants to use for his calculation
                cout<<"How many numbers do you want to enter? "<<endl;
                cin>>current;
                if(current<0){
                    cout<<"You cant enter a negative amount of numbers!"<<endl;
                }
                else{
                    break;
                }
            }
            current--;                                                                                          //Amount is substracted by 1 because the created list would be have one space too much otherwise
            const int amountc = current;
            float list[amountc];                                                                                //Array with enough space to safe all the numbers is created
            current = 0;
            while(amountc>=current){                                                                            //List is getting filled up with numbers selected by the user until its full
                cout<<"Number "<<current+1<<": ";
                cin>>list[current];
                cout<<endl;
                current++;
            }
            current = amountc;
            while(0<=current){                                                                                  //Sum of all the numbers in the list is created and saved
                sum += list[current];
                current--;
            }
            cout<<"The average of the entered numbers is "<<sum/(amountc+1)<<endl;                              //Average is calculated and is printed out
            current = amountc;
            while(0<=current){                                                                                  //All numbers of the list are getting compared, location of the highest one is safed
                if(list[max] < list[current]){
                    max=current;
                }
                else{
                    current--;
                }
            }
            cout<<"The highest number you entered  is "<<list[max]<<endl;                                       //Saved highest number of the list is printed out
        }
        else if(10==task){                                                                              //Program(while loop) is being ended
            cout<<"Programm was ended!"<<endl;
            break;
        }
        else if(0==task){                                                                               //How to navigate in the program is printed out
            cout<<"Task 5: 5"<<endl<<"Task 6: 6"<<endl<<"Task 7: 7"<<endl<<"Task 8: 8"<<endl<<"End Programm: 10"<<endl<<"Help: 0"<<endl;
        }
        else{                                                                                           //User is told that his Input was invalid
            cout<<"Task does not exist."<< endl;
        }
        cin.clear();
        cin.ignore();
    }
    return 0;
}
