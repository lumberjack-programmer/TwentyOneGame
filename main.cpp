#include <iostream>

using namespace std;

void total_cards(int cards_player[], int counter_cards_player){


 for (int i = 0; i < counter_cards_player; i++){
                if (cards_player[i] == 14){
                cout << "[King] ";
                } else
                if (cards_player[i] == 11){
                cout << "[Ace] ";
                } else
                if (cards_player[i] == 13){
                cout << "[Queen] ";
                } else
                if (cards_player[i] == 12){
                cout << "[Jack] ";
                } else {
                cout << "[" << cards_player[i] << "] ";
                }

        }


}


int main()
{
    int player1;
    int player2;

    int score1 = 0;
    int score2 = 0;


    int in1 = 0;
    int in2 = 0;
    bool queque = true;
    int select;
    while(true){


    cout << "\n1 -Continue\n0 -Exit!\n";
    cin >> select;

    int arr[2][52] = {{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14},{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1}};

    player1 = 0;
    player2 = 0;



    int cards_player1[50];
    int counter_cards_player1 = 0;
    int cards_player2[50];
    int counter_cards_player2 = 0;



    if (select == 1){
        while(true){




    if (queque){
        cout << "\n\nPlayer1: Type in how many cards do you want to pick up? "<< endl;
        cin >> in1;



    int card = 0;
    int total = 0;
    bool found = false;

    for (int i = 0; i < in1; i++){
        card = rand() % 14 + 1;
        found = false;

       // cout << "-----> " << card << endl;


        for (int i = 0; i < 52; i++){

                if (arr[0][i] == card && arr[1][i] != 0 ){

                     arr[1][i] = 0;

                    cards_player1[counter_cards_player1++] = card;
                     found = true;

                    if (card == 12){
                        total += 2;


                    } else
                    if (card == 13){
                        total += 3;


                    } else
                    if (card == 14){
                        total += 4;


                    } else {
                        total += card;


                    }
                        break;

                }

                if (i == 51 && found == false){
                    card = rand() % 14 + 1;

                //    cout << "-----> " << card << endl;


                    i = 0;
                }


            }

    }

/*
         for (int i = 0; i < 52; i++){
                cout << arr[0][i] << " - " << arr[1][i] << endl;
            }
*/
        player1 += total;

        printf("\nPlayer1: %d points. Cards: ", player1);
        total_cards(cards_player1, counter_cards_player1);
        //cout << "\nPlayer1: " << player1 << endl;

        queque = false;
    } else if (!queque){
        cout << "\n\nPlayer2: Type in how many cards do you want to pick up? "<< endl;
        cin >> in2;


        int card = 0;
        int total = 0;
        bool found = false;

    for (int i = 0; i < in2; i++){
        card = rand() % 14 + 1;
        found = false;

      //  cout << "-----> " << card << endl;





        for (int i = 0; i < 52; i++){

                if (arr[0][i] == card && arr[1][i] != 0 ){

                     arr[1][i] = 0;

                     cards_player2[counter_cards_player2++] = card;

                     found = true;

                    if (card == 12){
                        total += 2;

                    } else
                    if (card == 13){
                        total += 3;

                    } else
                    if (card == 14){
                        total += 4;

                    } else {
                        total += card;

                    }
                        break;



                }

                if (i == 51 && found == false){
                    card = rand() % 14 + 1;

             //       cout << "-----> " << card << endl;


                    i = 0;
                }


            }

    }

        /*
        for (int i = 0; i < 52; i++){
                cout << arr[0][i] << " - " << arr[1][i] << endl;
            }
*/

        player2 += total;
        //cout << "\nPlayer2: " << player2 << endl;
        printf("\nPlayer2: %d points. Cards: ", player2);
        total_cards(cards_player2, counter_cards_player2);
        queque = true;
    }


        // Results

    if (player1 == player2 && player1 >= 21 && player2 >= 21){
        cout << "\n\n___________________Draw__________________________________\n" << endl;

        //cout << "Total: Player1 " << player1;
        printf("Total: Player1 - %d points. Cards: ", player1);
        total_cards(cards_player1, counter_cards_player1);
        //cout << "\nTotal: Player2 " << player2;
        printf("Total: Player2 - %d points. Cards: ", player2);
        total_cards(cards_player2, counter_cards_player2);
        printf("\nPlayer1 won - %d times || Player2 won %d times", score1, score2);
        break;
    }

    if (player1 == 21){
        cout << "\n\n_________________________________________________________\n" << endl;

        //cout << "Total: Player1 - Winner! " << player1;
        printf("Total: Player1 - Winner! - %d points. Cards: ", player1);
        total_cards(cards_player1, counter_cards_player1);
        //cout << "\nTotal: Player2 - Loser! " << player2;
        printf("\nTotal: Player2 - Loser! - %d points. Cards: ", player2);
        total_cards(cards_player2, counter_cards_player2);
        printf("\nPlayer1 won - %d times || Player2 won - %d times", ++score1, score2);
        break;
    }
    if (player2 == 21){
        cout << "\n\n_________________________________________________________\n" << endl;
        //cout << "Total: Player2 - Winner! " << player2;
        printf("Total: Player2 - Winner! - %d points. Cards: ", player2);
        total_cards(cards_player2, counter_cards_player2);
        //cout << "\nTotal: Player1 - Loser! " << player1;
        printf("\nTotal: Player1 - Loser! - %d points. Cards: ", player1);
        total_cards(cards_player1, counter_cards_player1);
        printf("\nPlayer1 won - %d times || Player2 won - %d times", score1, ++score2);
        break;
    }

    if (player1 > 21){
        cout << "\n\n__________________________________________________________\n" << endl;
        //cout << "Total: Player2 - Winner! " << player2;
        printf("Total: Player2 - Winner! - %d points. Cards: ", player2);
        total_cards(cards_player2, counter_cards_player2);
        //cout << "\nTotal: Player1 - Loser! " << player1;
        printf("\nTotal: Player1 - Loser! - %d points. Cards: ", player1);
        total_cards(cards_player1, counter_cards_player1);
        printf("\nPlayer1 won - %d times || Player2 won - %d times", score1, ++score2);
        break;
    }

    if (player2 > 21){
        cout << "\n\n__________________________________________________________\n" << endl;
        //cout << "Total: Player1 - Winner! " << player1;
        printf("Total: Player1 - Winner! - %d points. Cards: ", player1);
        total_cards(cards_player1, counter_cards_player1);
        //cout << "\nTotal: Player2 - Loser! " << player2;
        printf("\nTotal: Player2 - Loser! - %d points. Cards: ", player2);
        total_cards(cards_player2, counter_cards_player2);
        printf("\nPlayer1 won - %d times || Player2 won - %d times", ++score1, score2);
        break;
    }




    }
    } else if (select == 0){
            return 0;
    }





    }




    return 0;
}
