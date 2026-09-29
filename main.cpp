#include <iostream>
#include "Image_Class.h"
using namespace std;

int main() {
    Image I("C:\\Users\\ASUS\\Downloads\\wallpaperflare.com_wallpaper (10).jpg");
    int choice =0 ;
    while (choice != 3) {


        cout << "enter your choice" << endl;
        cout <<"1- horizontal flip" << endl;
        cout <<"2- vertical flip" << endl;
        cout << "3- exit filter" << endl;
        cin >> choice ;

        if (choice == 1) {
            for (int i= 0 ; i < I.width / 2 ; i++) {
                int o = I.width -1 -i ;
                for (int j = 0 ; j < I.height ; j++ ) {
                    for (int k = 0 ; k < I.channels; k++ ) {
                        unsigned int H = I(i , j , k ) ;
                        I(i,j,k) = I(o , j , k);
                        I(o , j ,k) = H ;


                    }
                }


            }
            I.saveImage("C:\\Users\\ASUS\\Downloads\\b.png") ;
            cout <<"the image is horizontally flipped successfully" << endl;



        }
        else if (choice == 2) {
            for (int i= 0 ; i < I.width ; i++) {
                for (int j = 0 ; j < I.height/2 ; j++) {
                    int o =I.height -1 -j ;
                    for (int k = 0 ; k < I.channels ; k++ ) {
                        unsigned int V = I(i , j , k ) ;
                        I(i,j,k) = I(i , o, k);
                        I(i,o,k) = V ;
                    }
                }
            }
            I.saveImage("C:\\Users\\ASUS\\Downloads\\d.png") ;
            cout <<"the image is vertically flipped successfully" << endl;
        }
        else if (choice == 3) {
            cout << "exiting this filter" << endl;
            break ;
        }
        else {
            cout << "invalid choice try again" << endl;
        }
    }

    return 0;
}