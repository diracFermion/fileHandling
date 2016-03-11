#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using std::cout;
using std::endl;

std::ifstream positionfile ("../../SimulationData/position.txt");
std::string line;

char marker;
std::string step,filenum,filename;
std::string filetype = ".dat";
std::ofstream PosFile;

int main ()
{
  //int posFlag = 0,velFlag = 0; // indicator to keep track of analysis function calls
  while (std::getline(positionfile, line)) // Reading line by line
  {
      std::istringstream iss(line); // http://www.cplusplus.com/reference/sstream/istringstream/istringstream/

      iss >> marker;
      if ( marker == '$') {
          //posFlag = 0;
         //cout << "Read a special character $" << endl;
         iss >> step >> filenum;
         cout << step << "\t" << filenum << endl;
         filename = "postxtfiles/" + filenum + filetype;
         cout << filename << endl;


         PosFile.open(filename.c_str(), std::ofstream::out);
         //PosFile << line << endl;
         //cout << line << endl;
        }
      else if (marker == '#') {
          PosFile << line << endl;
          //cout << "Lattice Point Details" << endl;
          //iss >>config.pos[i][0] >> config.pos[i][1] >> config.pos[i][2] >> config.pos[i][3];
          //cout << config.pos[i][0] << "\t" << config.pos[i][1] << "\t" << config.pos[i][2] << "\t" << config.pos[i][3] << "\t" << endl;
          //i++;
          //cout << line<<endl;
        }
      else if (marker == '*')
        {
            PosFile.close();
        }

  }
}
