#include <iostream>
#include <vector>
#include "layers/DenseLayer.h"

#include <iostream>
#include <fstream>
#include <string>
#include<regex>
#include<ctype.h>
#include<stdlib.h>
#include "layers/loss_func.h"

std::vector<std::vector<double>> readcsv(std::string filename);
std::vector<std::vector<double>> get_dataset(std::vector<std::vector<double>> &data);

int main() {


    ANN::DenseLayer h1 = ANN::DenseLayer(784,64,"sigmoid");
    ANN::DenseLayer h2 = ANN::DenseLayer(64,16,"sigmoid");
    ANN::DenseLayer out = ANN::DenseLayer(16,10,"sigmoid");

    // a.print_weights();
    std::vector<std::vector<double>> o, x = {{1,1,1}, {0,0,0}, {2,2,2}};

    

    // o = a.feedforward(x);
    // for(auto x : o) {
    //     for (auto y : x) {
    //         std::cout<<y<<" ";
    //     }
    //     std::cout<<"\n";
    // }
    // std::cout<<"\n";
    // a.backpropogation({{1, 0}, {0, 0}, {1, 1}});
    // a.update_weights(100);
    // a.print_weights();


    std::vector<std::vector<double>> train_x,train_y,test_x,loss;
    train_x=readcsv("train.csv");
    test_x=readcsv("test.csv");
    train_y = get_dataset(train_x);

    std::vector<std::vector<double>> a1,a2,a3;
    std::vector<std::vector<double>> a4,a5,a6;
//    for (int i = 0; i < 30; i++) 
//     {
//         for(int j=0;j<train_y[0].size();j++)
//         {
//             std::cout<<train_y[i][j]<<" ";
//             // if(a3[i][j]>0)
//             //     finaloutput[i]=j;

//         }
//         std::cout<<" "<<'\n';
        
//     }


    // out.backpropagation(a3)
    
   

    std::cout<<train_y.size()<<" "<<train_y[0].size()<<'\n';
    std::cout<<train_x.size()<<" "<<train_x[0].size()<<'\n';

    
    std::cout<<test_x.size()<<" "<<test_x[0].size()<<'\n';

    
    for(int i=0;i<500;i++)
    {
        a1=h1.feedforward(train_x);
        a2=h2.feedforward(a1);
        a3=out.feedforward(a2);


        double l=0.0;

        ANN::Loss_function::loss_function("mse")(l,a3,train_y);
        ANN::Loss_function::d_loss_function("mse")(loss,a3,train_y);

        
        a4=out.backpropogation(loss);
        out.update_weights(0.05);
        a5=h2.backpropogation(a4);
        h2.update_weights(0.05);
        a6=h1.backpropogation(a5);
        h1.update_weights(0.05);

        
        
        

        
        // for(auto x : a3) {
        //     for (auto y : x) {
        //         std::cout<<y<<" ";
        //     }
        //     std::cout<<"\n";
        // }
        // std::cout<<"\n";

        std::cout<<l<<" "<<'\n';
    }

    std::cout<<a3.size()<<" "<<a3[0].size()<<'\n';
    std::vector<int> finaloutput (100,0);

    out.print_weights();

    for (int i = 0; i < 30; i++) 
    {
        for(int j=0;j<a3[0].size();j++)
        {
            std::cout<<a3[i][j]<<" ";
            // if(a3[i][j]>0)
            //     finaloutput[i]=j;

        }
        std::cout<<" "<<'\n';
        
    }
    
    // for(int j=0;j<100;j++)
    // {
    //     std::cout<<output[j]<<" "<<'\n';

    // }


    



    return 0;   
}




std::vector<std::vector<double>> readcsv(std::string filename) 
{

  std::string line;
  int i=0,j=0,k=0,len,last=0;
  std::string num = "";
  std::vector<std::vector<double>> arr = {};
  std::ifstream infile (filename);

  if(infile.is_open())
  {
    int t = 0;
    while ( getline(infile,line) )
    { 
        if(!t) {
            t++;
            continue;
        }
        std::vector<double> temp;
       k=0,last=0,j=0;
       len=line.length();

        while(k!=len){
                if(line[k]==','||k==len-1){



                    //for converting string into number
                    temp.push_back(atof(num.append(line,last,k).c_str()));
                    //cout<<"new entry -> "<<arr[i][j]<<" endl \n";

                    //Emtying string for getting next data
                    num="";

                    //increasing column number after saving data
                    j++;

                    if(k!=len-1)
                    last=k+1;
                }
                k++;
        }
        arr.push_back(temp);
        //increase row number for array
        i++;
    }
    //close the file
    infile.close();
  }
  else std::cout << "Unable to open file";

    // std::cout<<"Matrix of CSV file below \n";

    int col=0;

    //For finding the number of columns
        // for(int x=0;x<len;x++){
        // if(line[x]==',')
        // col++;
        // }
        // i= number of rows
        // col = number of columns
    // for(int l=0;l<i;l++){
    //         for(int m=0;m<=col;m++){
    //         std::cout<<arr[l][m]<<"\t";
    //         }
    // std::cout<<"\n";
    // }

    return arr;


}


std::vector<std::vector<double>> get_dataset(std::vector<std::vector<double>> &data) {
    std::vector<std::vector<double>> y (data.size(), std::vector<double>(10,0));
    for (int i = 0; i < data.size(); i++) {
        int t = (int) data[i][0];
        data[i].erase(data[i].begin());
        y[i] = std::vector<double>(10,0);
        y[i][t] = 1.0;
    }
    std::cout<<"Finished parsing..\n";
    return y;

}