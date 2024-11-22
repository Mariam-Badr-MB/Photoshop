/* 

Description : 

This menu is based on the user entering an image and then displays a list full of filters,
numbering 16 filters(light_dark,flip,merge,crop,resize,rotate,invert,grayscale , 
black and white, infrafed ,purble , detect , noise , sunlight , blur). After that,
the user chooses a filter from them. After that, the menu allows him to save 
the image either with a new name or the same name. After that, the user chooses 
either to continue in the list and choose a filter on the same picture, or he chooses 
another picture, or he writes the word “exit” and exits the program at any moment.



   */
#include<bits/stdc++.h>
#include "Image_Class.h"
using namespace std;

// Function clean invaild input
void clear_Input() ;
// Function light and dark filter
void choice_Light_Dark(Image& image) ;
// Function flip horizontal and vertical filter
void choice_flip(Image& image) ;
// Function merge resize and crop filter
void choice_merge(Image& image) ;
// Function crop filter
void choice_crop(Image& image) ;
// Function resize decrease and increase filter
void choice_resize(Image& image) ;
// Function rotate by angle( 90 , 180, 270 )filter
void choice_rotate(Image& image) ;
// Function frame filter
void choice_frame(Image& image) ;
// Function blur filter
void choice_blur(Image& image) ;
// Function invert filter
void Invert(Image& image);
// Function grayscaling filter
void gray_scale(Image& image);
// Function black and white filter
void black_white(Image& image);
// Function infrafed filter
void infrafed(Image& image) ;
// Function purble filter
void purble(Image& image) ;
// Function detectfilter
void Detect(Image& image) ;
// Function noise filter
void Noise(Image& image) ;
// Function sunlight  filter
void Sunlight_effect(Image& image) ;

int main(){
 
cout << "************************************************************Welcome at photoshop program************************************************************" << endl ;

int choice , x1 , x2 , y1 , y2 ;
Image image , image1 , image2 , newImage;
string filename  , new_or_not , save_filename , filename2 ;
bool f = false;

while (true){

 cout << endl ;
 cout << "1) load new image         " << endl; // Option for load image
 cout << "2) Grayscale conversion   " << endl; // Option for grayscale conversion
 cout << "3) Darken and Lighten     " << endl; // Option for darkening or lightening an image
 cout << "4) Invert image           " << endl; // Option for inverting an image
 cout << "5) Flip image             " << endl; // Option for flipping an image
 cout << "6) Black and white image  " << endl; // Option for black and white conversion
 cout << "7) Merge images           " << endl; // Option for Merge conversion
 cout << "8) Infrafed photography   " << endl; // Option for Infrafed conversion
 cout << "9) Purble image           " << endl; // Option for purble conversion
 cout << "10) Edge detect image     " << endl; // Option for detect conversion
 cout << "11) Crop image            " << endl; // Option for crop conversion
 cout << "12) Noise image           " << endl; // Option for noise conversion
 cout << "13) Add frame to image    " << endl; // Option for frame conversion
 cout << "14) Blur image            " << endl; // Option for blur conversion
 cout << "15) Rotat image           " << endl; // Option for rotate conversion
 cout << "16) Resize image          " << endl; // Option for resize conversion
 cout << "17) Sunlight image        " << endl; // Option for sunlight conversion
 cout << "18) Save image            " << endl; // Option for save edit
 cout << "19) Exit                  " << endl; // Option for exit
 cout << endl ;
 cout << "please, enter what you want: " ;
 cin >> choice ;                // User input for filter choice
 cout << endl ;

while(true){    
  if (1 <=  choice && choice < 20 ){
    break ;
  }else{
    clear_Input() ;
    cout << "Invalid input, Try again: " << endl ;
    cin >> choice ;
 }
}
if(choice == 1 ){

    cout << "Please, enter your image: " ;
    cin >> filename;  
    if( filename == "Exit"){                // exit program if user want it          
                exit(EEXIST);
    }  
   while(true){ 
    try {
        image.loadNewImage(filename);
        break ;
    } catch( invalid_argument) {
        cout << "Please enter a valid image: " ;
        cin >> filename;
        if(filename == "Exit"){          // exit program if user want it          
           exit(EEXIST);
        }
     }
   }
    cout << "Load image successfully" << endl ;
    f = true ;
 }else if(choice == 2 && f){                 // Grayscalying conversion          
    gray_scale(image) ;
    cout << "Modified Successfully" << endl ;
  }else if(choice == 3 && f){                // Darken and Lighten conversion 
    choice_Light_Dark(image) ;   
    cout << "Modified Successfully" << endl ;     
 }else if(choice == 4 && f){                 // flip conversion        
    Invert(image);
    cout << "Modified Successfully" << endl ;
 }else if(choice == 5  && f){               // Black and white conversion       
    choice_flip(image) ;
    cout << "Modified Successfully" << endl ;       
 }else if(choice == 6 && f){               // black_white conversion
    black_white(image) ;  
    cout << "Modified Successfully" << endl ;        
 }else if(choice == 7 && f){               // Merge conversion
    choice_merge(image) ;
    cout << "Modified Successfully" << endl ;
 }else if(choice == 8 && f){             // infrafed conversion  
    infrafed(image);
    cout << "Modified Successfully" << endl ;
 }else if(choice ==  9 && f){            // purple conversion
    purble(image) ;
    cout << "Modified Successfully" << endl ;  
 }else if(choice == 10 && f){            // Detect conversion
    Detect(image) ;
    cout << "Modified Successfully" << endl ;   
 }else if(choice == 11 && f){            // crop conversion
    choice_crop(image) ;
    cout << "Modified Successfully" << endl ;
 }else if(choice == 12 && f){            // Noise conversion
    Noise(image) ;
    cout << "Modified Successfully" << endl ;    
 }else if (choice == 13  && f){         // frame conversion
    choice_frame(image) ;
    cout << "Modified Successfully" << endl ;
 }else if (choice == 14  && f){       // Blur conversion
    choice_blur(image) ;
    cout << "Modified Successfully" << endl ;
 }else if (choice == 15  && f){       // Rotate conversion    
   choice_rotate(image) ;
   cout << "Modified Successfully" << endl ;
 }else if (choice == 16  && f){      // Resize conversion
   choice_resize(image) ;
   cout << "Modified Successfully" << endl ;
 }else if (choice == 17  && f){     // Sunlight conversion
    Sunlight_effect(image) ;
    cout << "Modified Successfully" << endl ;
 }else if (choice == 18 ){      
    if(f){ 
        while(true){           
            cout << endl ;
            cout << "As new image enter( Y ):                          " << endl ;
            cout << "As editing old image enter( N ):                  " << endl ;
            cout << endl ;
            cout << "please enter what you want: ";
            cin >> new_or_not;
            cout << endl ;           
            if( new_or_not == "Exit"){            // exit program if user want it          
                  exit(EEXIST);
            }else if (new_or_not == "N" || new_or_not == "n") {        
                        image.saveImage(filename);                                             
                        cout << endl ;
                        cout << "New Image saved as "<< filename << " successfully!  " << endl;
                        cout << endl ;            
                break ;
            }else if (new_or_not == "Y" || new_or_not == "y") {
                cout << "Please enter image name to store new image, \n";
                cout << "You should specify extension (jpg , bmp , png , tga): "; 
                cin >>  save_filename ;
                if( save_filename == "Exit"){           // exit program if user want it           
                      exit(EEXIST);
                 }
                while(true){ 
                try {
                        image.saveImage(save_filename);          
                        cout << endl ;
                        cout << "New Image saved as "<<  save_filename << " successfully!  " << endl;
                        cout << endl ;
                        break ;                         
                }catch( invalid_argument) {
                        cout << "Please, enter a valid image:  " << endl;
                        cin >> save_filename;
                        if(save_filename == "Exit"){         // exit program if user want it          
                              exit(EEXIST);
                          }
                }
                }
                break;

            }else {

                cout << "Invalid input,Try again: " << endl ;
                clear_Input();
            }
        }
    }else{
        cout << "You did not enter image." << endl ;       
    }
 }else if (choice == 19 ){
    exit(EEXIST);   
 }else{
    cout << "please enter image to be able use filter." << endl ;
 }
        // Rest of the main function continues with processing user choices...
 }
    return 0 ;
}
void clear_Input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Function  gray_scale Image
void  gray_scale(Image& image){
  
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize average value
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); // Accumulate pixel values
            }
            avg /= 3; // Calculate average

            // Set all channels to the average value
             
            for (int k = 0; k < 3; ++k) {

                image(i, j, k) = avg ; // Accumulate pixel values
            }          
        }
    }
}
// Function  Darken and Light Image
void  Darken(Image& image , double& ratio ){
  
    for (int i = 0; i < image.width; ++i) {

        for (int j = 0; j < image.height; ++j) {

            for (int k = 0; k < 3; ++k) {
               
               if(ratio == 0){
                       
                        image(i, j, k) ;
                
               }else if (ratio == 100){

                       image(i, j, k) = 0 ;
               } else{
                         image(i, j, k)  /= (100 / ratio);   // decrease colore make photo dark  
               }                
            }          
        }
    }
}
void  Light(Image& image , double& ratio){

    for (int i = 0; i < image.width; ++i) {

        for (int j = 0; j < image.height; ++j) {
            
            for (int k = 0; k < 3; ++k) {

              if(image(i,j,k) * (100 / ratio )  > 255) {      
                    
                    image(i,j,k) = 255 ;       // sure value willnot iecrease 255
                          
              }
              if (ratio == 0){

                image(i , j , k) *= 1 ;

              }else if (ratio == 100){

                image(i , j , k) = 255 ;

              }else{
                image(i,j,k) *=( 100 / ratio  );            // increase colore make photo light
              }
            } 
        }
    }
}
void choice_Light_Dark(Image& image){             // Darken and Light conversion   
    string filename  ;
    string L_D ;
    double  ratio;
    cout << "A) Darken image" << endl;
    cout << "B) Lighten image" << endl;
    cout << endl ;
    cout << "please, enter what you want: " ;
    cin >> L_D ;
    if(L_D == "Exit"){             // exit program if user want it           
         exit(EEXIST);
    }
    while(true){          
        if(L_D == "A" || L_D == "B" || L_D == "a" || L_D == "b"){                 
                 break;
        } else{
            clear_Input() ;
            cout << "Invalid input, try again " << endl ;
            cin >> L_D ;
            if(L_D == "Exit"){            // exit program if user want it           
                  exit(EEXIST);
             }
        }
    }   
    cout <<"Please, enter precent of dark or light : ";
    cin >> ratio ;
    while(true){
        if(0 <= ratio <= 100){
            break ;
        }else{
            cout << "invalid input (recent should be between (0, 100)), Try again: " ;
            cin >> ratio ;
        }
    }
    if(L_D == "A" || L_D == "a" ){       
        Darken(image, ratio); 
    } else{
     
        Light(image, ratio);
    }       
 }
// Function  Invert Image
void  Invert(Image& image){           
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; 
            for (int k = 0; k < 3; ++k) {                       
                 image(i,j,k) = 255 -  (image(i,j,k)  ) ;
            }          
        }
    }
} 
// Function to flip the image horizontally
void flip_vertical(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height/2; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Swap pixel values between the left and right sides
                swap(image(i, j, k), image(i, image.height - j - 1, k));
            }
        }
    }
}
// Function to flip the image vertically
void flip_horizontal(Image& image) {
    for (int i = 0; i < image.width/2; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Swap pixel values between the top and bottom halves
                swap(image(i, j, k), image(image.width-i - 1 , j , k));
            }
        }
    }
}
void choice_flip(Image& image){                                              
    string filename  , new_or_not ;
    string angle;
     cout << "please, enter what you want horizomtal or vertical(H/V): " ;
     cin >> angle ;
     cout << endl ;
    if( filename == "Exit"){             // exit program if user want it           
                 exit(EEXIST);
    }
     while(true){         
        if(angle == "H" || angle == "h" || angle == "v" || angle == "V"){                 
             break;
        } else{
            clear_Input() ;
            cout << "Invalid input, try again "  ;
            cin >> angle ;
            if( filename == "Exit"){                // exit program if user want it           
                 exit(EEXIST);
            }else{                        
                continue;
            }
        }
    }
    if(angle == "H" || angle == "h" ){                 
        flip_horizontal(image);
    } else{             
        flip_vertical(image) ;
    }
 }
// Function  black and white Image
void black_white(Image& image){     
    unsigned int threshold = 128;
    for(int i = 0 ;i < image.width;++i){// to loop in the width of the message
        for (int j = 0 ; j < image.height;++j){// to loop in the hight of the message
            unsigned int average = 0;
            for(int k = 0 ; k < 3 ; ++k){// to loop in the 3 channel (R,G,B)
                average+= image(i ,j,k ) ;
            }
            average =(average/3);            
            if(average<128)
                average = 0;
            else
                average = 255;
            for(int k = 0 ; k < 3 ; k++){
              image(i,j,k) =average;

            }
        }
    }
}
void merge_commen(Image& image, Image& image2) {
    int mergedHeight = min(image.height, image2.height);
    int mergedWidth = min(image.width, image2.width);
    Image merged(mergedWidth, mergedHeight);
    for (int i = 0; i < mergedWidth; ++i) {
        for (int j = 0; j < mergedHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Average the corresponding pixel values
                unsigned int avg = (image(i, j, k) + image2(i, j, k)) / 2;
                // Assign the averaged value to the merged image
                merged(i, j, k) = avg;
            }
        }
    }
    // Assign the merged image back to the first image
    image = merged;
}
void  merge(Image& image , Image& image2 ){
    if (image.width > image2.width ) {
        Image resizedImage2(image.width, image.height);
        Image merged(image.width, image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                int newpixels1 = i * (image2.width - 1) / (image.width - 1);
                int newpixels2 = j * (image2.height - 1) / (image.height - 1);
                resizedImage2(i, j, 0) = image2(newpixels1, newpixels2, 0);
                resizedImage2(i, j, 1) = image2(newpixels1, newpixels2, 1);
                resizedImage2(i, j, 2) = image2(newpixels1, newpixels2, 2);
            }
        }
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                unsigned int avg = 0;
                for (int k = 0; k < 3; ++k) {
                    avg = image(i, j, k) + resizedImage2(i, j, k);
                    if (avg > 255) {
                        avg = 255;
                    }
                    merged(i, j, k) = avg ;
                }
            }
        }
        image = merged;
    } else {
        Image resizedImage1(image2.width, image2.height);
        Image merged(image2.width, image2.height);
        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height; ++j) {
                int newpixels1 = i * (image.width - 1) / (image2.width - 1);
                int newpixels2 = j * (image.height - 1) / (image2.height - 1);
                resizedImage1(i, j, 0) = image(newpixels1, newpixels2, 0);
                resizedImage1(i, j, 1) = image(newpixels1, newpixels2, 1);
                resizedImage1(i, j, 2) = image(newpixels1, newpixels2, 2);
            }
        }
        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height; ++j) {
                unsigned int avg = 0;
                for (int k = 0; k < 3; ++k) {
                    avg = image2(i, j, k) + resizedImage1(i, j, k);
                    if (avg > 255) {
                        avg = 255;
                    }
                    merged(i, j, k) = avg ;
                }
            }
        }
        image = merged;
    }
}
void merge_resize_S(Image& image, Image& image2) {   
    if (image.width > image2.width ) {
        Image resizedImage1(image2.width, image2.height);
        Image merged(image2.width, image2.height);
        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height; ++j) {
                int newpixels1 = i * image.width - 1 / (image2.width - 1);
                int newpixels2 = j * image.height - 1 / (image2.height - 1);
                resizedImage1(i, j, 0) = image(newpixels1, newpixels2, 0);
                resizedImage1(i, j, 1) = image(newpixels1, newpixels2, 1);
                resizedImage1(i, j, 2) = image(newpixels1, newpixels2, 2);
            }
        }
        for (int i = 0; i < image2.width; ++i) {
            for (int j = 0; j < image2.height; ++j) {
                unsigned int avg = 0;
                for (int k = 0; k < 3; ++k) {
                    avg = image2(i, j, k) + resizedImage1(i, j, k);
                    if (avg > 255) {
                        avg = 255;
                    }
                    merged(i, j, k) = avg ;
                }
            }
        }
    image = merged ;
    } else {
        Image resizedImage2(image.width, image.height);
        Image merged(image.width , image.height);
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                int newpixels1 = i * (image2.width - 1) / (image.width - 1);
                int newpixels2 = j * (image2.height - 1) / (image.height - 1);
                resizedImage2(i, j, 0) = image2(newpixels1, newpixels2, 0);
                resizedImage2(i, j, 1) = image2(newpixels1, newpixels2, 1);
                resizedImage2(i, j, 2) = image2(newpixels1, newpixels2, 2);
            }
        }
        for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                unsigned int avg = 0;
                for (int k = 0; k < 3; ++k) {
                    avg = image(i, j, k) + resizedImage2(i, j, k);
                    if (avg > 255) {
                        avg = 255;
                    }
                    merged(i, j, k) = avg ;
                }
            }
        }
    image = merged ;
    }
}
void choice_merge(Image& image) {
    string  filename2, C_R;   
    Image image2;

    cout << "A) by common area" << endl;
    cout << "B) by resizing small image to add in big image" << endl;
    cout << "C) by resizing big image to add in small image" << endl;
    cout << endl;
    cout << "Please enter your choice (A, B, C) or 'Exit' to exit: ";
    cin >> C_R;

    if (C_R == "Exit") {
        exit(EXIT_FAILURE);
    }

    while (true) {

        char choice = tolower(C_R[0]);

        if (choice == 'a' || choice == 'b' || choice == 'c') {
            break;

        } else {
            clear_Input();
            cout << "Invalid input, Try again: ";
            cin >> C_R;
        }
    }
    cout << endl;
    cout << "Please enter the name of image2: ";
    cin >> filename2;

    if (filename2 == "Exit") {
        exit(EEXIST);
    }

    while (true) {
        try {

            image2.loadNewImage(filename2);
            break;

        } catch (invalid_argument) {

            cout << "Please enter a valid image: ";
            cin >> filename2;

            if (filename2 == "Exit") {
                exit(EEXIST);
            }
        }
    }
 // Assuming Image class has a default constructor
 
    if (tolower(C_R[0]) == 'a') {

        merge_commen(image, image2);

    } else if (tolower(C_R[0]) == 'c') {

        merge_resize_S(image, image2);

    } else {
        merge(image, image2);
    }

}

void  infrafed(Image& image){

        for (int i = 0; i < image.width; ++i) {

        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; 

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); 
            }

            avg /= 3 ;    
            for (int k = 1; k < 3; ++k) {

                image(i, j, k) = 255 - avg  ;
      
                image(i, j, 0) = 255 ;
            }     
        }
    }
}

 void purble(Image& image){ 

    for(int i = 0 ;i < image.width;++i){

        for (int j = 0 ; j < image.height;++j){
   
                 image(i , j , 1) *= .7 ;

                 if( image(i , j , 1) > 255){

                     image(i , j , 1) = 255;

                 }  
        } 
     }  
        
 }  

void Detect(Image& image) {  
    int height = image.height;
    int width = image.width;
    // Sobel kernels for horizontal and vertical gradients
    int Ix[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Iy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    // Initialize gradient magnitudes
    vector<vector<int>> gradients(height, vector<int>(width, 0));
    // Apply Sobel operator to calculate gradients
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int gradX = 0, gradY = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    gradX += image(x + i, y + j, 0) * Ix[i + 1][j + 1];
                    gradY += image(x + i, y + j, 0) * Iy[i + 1][j + 1];
                }
            }
            // Calculate gradient magnitude
            gradients[y][x] = sqrt(gradX * gradX + gradY * gradY);
        }
    }
    int Edges = 120 ; 
    for (int y = 0; y < height; ++y) {       
        for (int x = 0; x < width; ++x) {
            if (gradients[y][x] > Edges) {
                // Set edge pixel to black
                image(x, y, 0) = 0;
                image(x, y, 1) = 0;
                image(x, y, 2) = 0;
            } else {
                // Set non-edge pixel to white
                image(x, y, 0) = 255;
                image(x, y, 1) = 255;
                image(x, y, 2) = 255;
            }
        }
    }
}
// Function to crop an image
Image cropImage(Image& image, int X, int Y, int Width, int height) {  
    // Create a new image for the cropped region
    Image cropped_image(Width, height);
    // Perform cropping
    for (int i = 0; i < Width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < 3; ++k) {
                cropped_image(i, j, k) = image(i + X, j + Y, k);
            }
        }
    }
    // Return the cropped image
    return cropped_image;
}
void choice_crop(Image& image){
    string filename;
    int X, Y, Width, height; 
    while(true){        
         cout << "Please, enter the starting points x and y: ";
         cin >> X >> Y ;
         cout << "Please,  enter the dimensions of width and height (W and H): ";
         cin >> Width >> height;

     // Check if the cropping region exceeds the bounds of the original image

         if (X < 0 || Y < 0 || Width <= 0 || height <= 0 || X + Width > image.width || Y + height > image.height) {
              cout << "Invalid cropping dimensions or starting points. Try again: " << endl;

        // Return the original image if cropping is not successful
         }else{
             break ;
          }
     }
    // Crop the image
    image = cropImage(image , X, Y, Width, height);

}
  
void Noise(Image& image) {
    for (int y = 0; y < image.height; y += 2) {
        for (int x = 0; x < image.width; ++x) {
            for (int k = 0; k < 3; ++k) {
                image(x, y, k) = 0; // Black color for scanlines
            }
        }
    }

    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            if (rand() % 3 == 0) { // Increase noise intensity
                for (int k = 0; k < 3; ++k) {
                    image(x, y, k) = rand() % 256;
                }
            }
        }
    }
}

unordered_map<string, tuple<int, int, int>> colorMap = {

    { "black" , {0   , 0   , 0  } },
    { "white" , {255 , 255 , 255} },
    { "red"   , {255 , 0   , 0  } },
    { "green" , {0   , 255 , 0  } },
    { "blue"  , {0   , 0   , 255} },

};

void Simple_frame(Image& image, int thickness, int r, int g, int b) {
    // Add simple frame to the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < thickness || i >= image.width - thickness || j < thickness || j >= image.height - thickness) {
                // Set pixel color to frame color
                image(i, j, 0) = r;
                image(i, j, 1) = g;
                image(i, j, 2) = b;
            }
        }
    }
}

void Decorated_frame(Image& image, int thickness, int r, int g, int b) {
    // Add decorated frame to the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i < thickness || i >= image.width - thickness || j < thickness || j >= image.height - thickness) {
                // Set pixel color to frame color
                image(i, j, 0) = r;
                image(i, j, 1) = g;
                image(i, j, 2) = b;

                // Add some pattern to the frame

                if ((i + j) % 3 == 0) {
                    
                    image(i, j, 0) = 255; // Red
                    image(i, j, 1) = 0;   // Green
                    image(i, j, 2) = 0;   // Blue
                }
            }
        }
    }
}

void choice_frame(Image& image){            
   
    string filename;
    int thickness;

    cout << "Please enter the frame thickness: ";
    cin >> thickness;

    string color_name;

   while(true){

     cout << "Please enter the frame color name (black, white, red, green, blue): ";
     cin >> color_name;

     transform(color_name.begin(), color_name.end(), color_name.begin(), ::tolower);
     auto it = colorMap.find(color_name);
   
     if (it == colorMap.end()) {

        cout << "Invalid color name.Try again: " << endl; 

     }else{
              
        tuple<int, int, int> rgb = it->second;
        int r = get<0>(rgb);
        int g = get<1>(rgb);
        int b = get<2>(rgb);

        string choice;

        cout << "Do you want to add a simple frame (S) or a decorated frame (D):  ";
        cin >> choice;
   
        while(true){  

            if (choice == "S" || choice == "s"){

               Simple_frame(image, thickness, r, g, b);
               break ;

             } else if (choice == "D" || choice == "d") {

               Decorated_frame(image, thickness, r, g, b);
               break ;
        
             } else {
                 cout << "Invalid choice, Try again: " << endl;
                 cin >> choice;
             }
        }
        break ;
     }
   }  
 }
void Blur(Image& image , int& blr_Rad) {

    for (int y = 0; y < image.height; ++y) {

        for (int x = 0; x < image.width; ++x) {

            int count = 0;
            int t_Red = 0, t_Green = 0, t_Blue = 0;

            for (int ky = -blr_Rad; ky <= blr_Rad; ++ky) {

                for (int kx = -blr_Rad; kx <= blr_Rad; ++kx) {

                    int nx = x + kx;
                    int ny = y + ky;

                    if (nx >= 0 && nx < image.width && ny >= 0 && ny < image.height) {

                        t_Red += image(nx, ny, 0);
                        t_Green += image(nx, ny, 1);
                        t_Blue += image(nx, ny, 2);
                        count++;
                    }
                }
            }
            unsigned char avgRed = t_Red / count;
            unsigned char avgGreen = t_Green / count;
            unsigned char avgBlue = t_Blue / count;

            image(x, y, 0) = avgRed;
            image(x, y, 1) = avgGreen;
            image(x, y, 2) = avgBlue;
        }
    }
}

void choice_blur(Image& image){            
   
    string filename;
    int blr_Rad;
 
    cout << "Please, enter Crystal ratio between(0 , 100): ";
    cin >> blr_Rad;

    while(true){

        if(blr_Rad > 0 &&  blr_Rad < 100){ 

            break ;

        }else{

            cout << "Invalid ratio, Try again: " ;
            cin >> blr_Rad ;

        }
    }
    Blur(image , blr_Rad) ;

 }

void rotate270(Image& image) {
    Image rotatedImage(image.height, image.width);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Assign pixels from original image to rotated image with swapped coordinates
                rotatedImage(j, i, k) = image(i, j, k);
            }
        }
    }

    for (int i = 0; i < rotatedImage.width; ++i) {
        for (int j = 0; j < rotatedImage.height / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Swap pixel values between the left and right sides
                swap(rotatedImage(i, j, k), rotatedImage(i, rotatedImage.height - j - 1, k));
            }
        }
    }

    image = rotatedImage;
}

void rotate180(Image& image) {
    // Function to flip the image horizontally
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Swap pixel values between the top and bottom halves
                swap(image(i, j, k), image(i, image.height - j - 1, k));
            }
        }
    }

    // Function to flip the image vertically
    for (int i = 0; i < image.width / 2; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Swap pixel values between the left and right halves
                swap(image(i, j, k), image(image.width - i - 1, j, k));
            }
        }
    }
}

void rotate90(Image& image) {

    Image rotatedImage(image.height, image.width);

    for (int i = 0; i < image.width; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // Assign pixels from original image to rotated image with swapped coordinates
                    rotatedImage(j, i, k) = image(i, j, k);
                }
            }
        }
        for (int i = 0; i < rotatedImage.width; ++i) {

            for (int j = 0; j < rotatedImage.height / 2; ++j) {
                for (int k = 0; k < 3; ++k) {
                    // Swap pixel values between the left and right sides
                    swap(rotatedImage(i, j, k), rotatedImage(i, rotatedImage.height - j - 1, k));
                }
            }
        }

// Function to flip the image vertically

    for (int i = 0; i < rotatedImage.width / 2; ++i) {

        for (int j = 0; j < rotatedImage.height; ++j) {

            for (int k = 0; k < 3; ++k) {

                // Swap pixel values between the top and bottom halves
                swap(rotatedImage(i, j, k), rotatedImage(rotatedImage.width - i - 1, j, k));
            }
        }
    }

    for (int i = 0; i < rotatedImage.width; ++i) {
        for (int j = 0; j < rotatedImage.height / 2; ++j) {
            for (int k = 0; k < 3; ++k) {
                swap(rotatedImage(i, j, k), rotatedImage(i, rotatedImage.height - j - 1, k));
            }
        }
    }
    image = rotatedImage ;
}

void choice_rotate(Image& image){            
   
    string filename;
    string angle;
 
    cout << "Please enter the angle (90, 180, 270): ";
    cin >> angle;

    while(true){

        if(angle == "90"){

            rotate90(image) ;
            break ;

        }else if (angle == "180"){

            rotate180(image);
            break ;

        }else if (angle == "270"){

            rotate270(image);
            break ;
            
        }else{

            cout << "Invalid angle, Try again: " ;
            cin >> angle ;

        }
    }
 }

 // Function to resize an image
Image resizeImage(Image& image, int newWidth, int newHeight, Image& newImage) {

    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            int newPixelX = i * image.width / newWidth;
            int newPixelY = j * image.height / newHeight;
                
                // Create the resized image once
            newImage(i, j, 0) = image(newPixelX, newPixelY, 0);
            newImage(i, j, 1) = image(newPixelX, newPixelY, 1);
            newImage(i, j, 2) = image(newPixelX, newPixelY, 2);
        }
    }
    return newImage ;
}

void choice_resize(Image& image){     

    string filename;
    int width2, height2;

    cout << "Please, nter the new the image width : ";
    cin >> width2 ;

    while(true){

     if(cin.fail() || width2 <= 0){

            cout << "Invalid input, Try again: " << endl ;
            cin >> width2 ;

     }else{
             break ;
     }
    }
    
    cout << "Please, enter the new the image height : ";
    cin >> height2;

    while(true){

     if(cin.fail() || height2 <= 0){

            cout << "Invalid input, Try again: " << endl ;
            cin >> height2 ;

     }else{
             break ;
     }
    }

    Image newImage(width2, height2);  // Create the resized image once

    image = resizeImage(image, width2, height2, newImage);
 }

void Sunlight_effect(Image& image) {
    // Define sunlight color and intensity
    const int sun_intens = 64;
    const int sun_col[] = {255, 255, 0};

    // Apply sunlight effect
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                int New_value = image(i, j, k) + sun_intens * sun_col[k] / 255;
                if (New_value > 255) {
                    image(i, j, k) = 255;
                } else {
                    image(i, j, k) = New_value;
                }
            }
        }
    }
}