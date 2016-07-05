#// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
using namespace std;
void display(vector<string> &pieces);
void getDAG(int j1,int i1);
float findpaths(int source ,int target ,int totalnode,int totaledge,float max );
inline void print_path(vector<int>path);
bool node_present(int node,vector<int>path);
vector<vector<int> >GRAPH(100);
vector<string> inputs;
vector<string> outputs;
vector<string> wires;
vector<string> regs;
vector<string> combo;
int r; //number of registers
int o; //number of outputs
int reg[35];
float delay_of_r=0;   //delay of reg component

struct node{   // Declare PERSON struct type
                  string output;   // Declare member types
                  string input1;
                  string input2;
                  string input3;
                  string operation;
                  string delay;
                            };
                node line[35];
                float l2=0;
                int R_FLAG=0;

int main(int argc, char** argv) {

	
	if( argc != 4 && argc != 5 ) {
		cerr << endl << "Usage: " << argv[0] << " -cp techlib netlist " << endl << endl;
		return -1;
	}
	
	if( string(argv[1]) == "-cp") {
		if( argc != 4 ) {
			cerr << endl << "Usage: " << argv[0] << " -cp techlib netlist" << endl << endl;
			return -1;
		}

		cout << "Command Executed: " << argv[0] << " " << argv[1] << " " << argv[2] << " " << argv[3] << endl;
	}
	else {
		cerr << endl << "Usage: " << argv[0] << " -cp techlib netlist" << endl << endl;
		return -1;
	}

    /////////////////
    struct delay{
                  string type;
                  string quantity;
                  string delay;
                };
                delay n_delay[35];

                //////////////////////////////////
  string line1;
    string line2;
    string line3;
string str4;
string temp;
string word;
int token_cnt=0;
int C_FLAG=0;
int W_FLAG=0;
int I_FLAG=0;
int O_FLAG=0;
int FLAG2=0;
int i=0;
int k=0;
int v1=0;
int v2=0;
int k4;
int k3;
int z1[100];
int z2[100];
int z3=0;
int i1=0;
int i2=0;
int source[35];
int sink[35];
int sinkr[35];
int sourcer[35];
int sinko[35];
float max=0;
int COUNT=0;

//stringstream s;
vector<string> pieces;
   char b;
  ifstream myfile1 (argv[3]);
    if (myfile1.is_open())
    {
      while(!myfile1.eof())
        {
            getline (myfile1,line1);





            if(line1.empty())
            {}
            else
            {
                if((line1.find("//") != std::string::npos))
                 {}
                else { if((line1.find_first_of('='))!=-1)

  //////////////////////////////////////////////////////////////////
                {if(COUNT==0){cout<<"Equations are given before parameters declaration";return -1;}
                    char character1[] = {'+','-','*'};
                char character2[] = {'?',':'};
                char character3[] = {'>','<'};

                vector<string> tokens;
                                 stringstream s(line1);
                                string temp;
                                while(s>> temp)
                                {//cout<<temp;

                                    tokens.push_back(temp);
                                }
//cout<<"token count is  "<<tokens.size()<<endl;

                        int pos = line1.find_first_of(character1, 0, sizeof(character1));
                           if ((pos != string::npos) && (tokens.size()==5))
                            {

                                line[i].output=tokens[0];
                                line[i].input1=tokens[2];
                                line[i].input2=tokens[4];
                                line[i].input3="0";
                                line[i].operation=tokens[3];///////////array of objects///////operation is +,-,*
                                //////////////////
                                if((line[i].operation)=="+"){line[i].operation="ADD32";}
                                if((line[i].operation)=="*"){line[i].operation="MUL32";}
                                if((line[i].operation)=="-"){line[i].operation="SUB32";}



                                /////////////////////////

                                i=i+1;
                            }
         else
           {
    int pos = line1.find_first_of(character2, 0, sizeof(character2));
    if((pos != string::npos) && (tokens.size()==7))
    {                           line[i].output=tokens[0];
                                line[i].input1=tokens[2];
                                line[i].input2=tokens[4];
                                line[i].input3=tokens[6];
                                line[i].operation="MUX2x1";///////////? in operation

                                i=i+1;}
    else{
    string s1="<<";
    string s2=">>";
             if (((line1.find(s1) != std::string::npos) || (line1.find(s2) != std::string::npos)) && (tokens.size()==5))
                               {line[i].output=tokens[0];
                                line[i].input1=tokens[2];
                                line[i].input2=tokens[4];
                                line[i].input3="0";
                                if(line1.find(s1) != std::string::npos){line[i].operation="SHL";}
                                else{line[i].operation="SHR";}

                                i=i+1;}//shift operation

                  else{
                      int pos = line1.find_first_of(character3, 0, sizeof(character3));
                                if((pos !=string::npos) && (tokens.size()==5))
                                {line[i].output=tokens[0];
                                line[i].input1=tokens[2];
                                line[i].input2=tokens[4];
                                line[i].input3="0";
                                line[i].operation=tokens[3];
                                if((line[i].operation)=="<"){line[i].operation="COMPLT";}
                                if((line[i].operation)==">"){line[i].operation="COMPGT";}

                                i=i+1;}
                                else{string s1="==";
                                    if((line1.find(s1)!=std::string::npos) && (tokens.size()==5))
                                    {line[i].output=tokens[0];
                                line[i].input1=tokens[2];
                                line[i].input2=tokens[4];
                                line[i].input3="0";
                                line[i].operation="COMPEQ";

                                i=i+1;}
                                else{if(tokens.size()==3){



                                        line[i].output=tokens[0];
                                line[i].input1=tokens[2];
                                line[i].input2="0";
                                line[i].input3="0";}
                                else{cout<<"invalid tokens";return -1;}

                                for(int v=0;v<outputs.size();++v)
                                {if(line[i].output.compare(outputs[v])==0)
                                    {line[i].operation="OUTPUT";v1=1;}
                                }
                                  if(v1==0){line[i].operation="REG";}
                                i=i+1;}
                                   }
}
           }

                }
                }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////












                  else {COUNT=COUNT+1;////////////////////////////////
                       int end;
                end = line1.find(":");
                if(end>=0)
                {int beginning=0;
                word = line1.substr(beginning,end);
                beginning = end + 1;
                b=word[0];





////////////////////////////////////////////////////////////inputs,outputs,regs,wires////////////////////////////////////////////////////////////////////
string W="WIRES";
string O="OUTPUTS";
string R="REGS";
string I="INPUTS";
if((word.find(I))!=std::string::npos)
{
I_FLAG=1;


line2=line1.substr(beginning);
stringstream s(line2);
   while(s>> temp)
   {
     inputs.push_back(temp);
   }
   for(int b1=0;b1<inputs.size();b1++)
                 {string b2=inputs[b1];
                      combo.push_back(b2);
                 }
   for(int i7=0;i7<inputs.size();i7++)
            {k4=0;
                for(int i8=0;i8<inputs.size();i8++)
            {if((inputs[i8].compare(inputs[i7]))==0)
            {k4=k4+1;}
            }
            if(k4>1){cout<<"inputs are mentioned more than one times";return -1;}
            }

}
        else {
                if((word.find(O))!=std::string::npos)

                {O_FLAG=1;

                  line2=line1.substr(beginning);
                  stringstream s(line2);
                  while(s>> temp)
                    {
                      outputs.push_back(temp);
                    }
                    for(int b1=0;b1<outputs.size();b1++)
                 {string b2=outputs[b1];
                      combo.push_back(b2);
                 }
                       for(int i7=0;i7<outputs.size();i7++)
            {k4=0;
                for(int i8=0;i8<outputs.size();i8++)
            {if((outputs[i8].compare(outputs[i7]))==0)
            {k4=k4+1;}
            }
            if(k4>1){cout<<"outputs are mentioned more than one times";return -1;}
            }



                }
                    else if((word.find(W))!=std::string::npos)

                          {W_FLAG=1;

                                line2=line1.substr(beginning);
                                stringstream s(line2);
                                while(s>> temp)
                                {
                                    wires.push_back(temp);
                                }
                                for(int b1=0;b1<wires.size();b1++)
                 {string b2=wires[b1];
                      combo.push_back(b2);
                 }
                                   for(int i7=0;i7<wires.size();i7++)
            {k4=0;
                for(int i8=0;i8<wires.size();i8++)
            {if((wires[i8].compare(wires[i7]))==0)
            {k4=k4+1;}
            }
            if(k4>1){cout<<"wires are mentioned more than one times";return -1;}
            }


                          }
                                  else if((word.find(R))!=std::string::npos)
                                        { R_FLAG =1;

                                                line2=line1.substr(beginning);
                                                stringstream s(line2);
                                                while(s>> temp)
                                                  {
                                                     regs.push_back(temp);
                                                  }
                                                  for(int b1=0;b1<regs.size();b1++)
                 {string b2=regs[b1];
                      combo.push_back(b2);
                 }
                                                     for(int i7=0;i7<regs.size();i7++)
            {k4=0;
                for(int i8=0;i8<regs.size();i8++)
            {if((regs[i8].compare(regs[i7]))==0)
            {k4=k4+1;}
            }
            if(k4>1){cout<<"registers are mentioned more than one times";return -1;}
            }



                                        }
                                        else{cout<<"Parameters are not given properly";return -1;}

            }
////////////////////////////////////////////////////////////////////////////////////////////////////////
                 }
                 else
                 {cout<<"parameters are not on single line";return -1;}

                   }
                   /////


            }

            }

        }


        ///////////////////////////////////chk repetition///////////////////////////////


///////////////////////////////////////////////////checking//////////////////////////////////////////////////////
for(int b=0;b<combo.size();++b){
for (int b1=0;b1<combo.size();++b1)
{if(combo[b]==combo[b1]){C_FLAG=C_FLAG+1;}
}
//cout<<C_FLAG<<endl;
if(C_FLAG>1){cout<<"Parameters are declared more than once ";return -1;}
C_FLAG=0;
}
///////////////////////to check if all literals are there/////////
int v3=0;
for(int v1=0;v1<i;++v1)
{for(int v2=0;v2<combo.size();++v2)
{if(line[v1].input1==combo[v2]){v3=v3+1;}}
if(v3==0){cout<<"Operand not declared ";return -1;}
v3=0;
}
v3=0;
for(int v1=0;v1<i;++v1)
{for(int v2=0;v2<combo.size();++v2)
{if((line[v1].input2==combo[v2]) || (line[v1].input2=="0")){v3=v3+1;}}
if(v3==0){cout<<"Operand not declared ";return -1;}
v3=0;
}
v3=0;
for(int v1=0;v1<i;++v1)
{for(int v2=0;v2<combo.size();++v2)
{if((line[v1].input3==combo[v2]) || (line[v1].input3=="0")){v3=v3+1;}}
if(v3==0){cout<<"Operand not declared ";return -1;}
v3=0;
}
v3=0;
for(int v1=0;v1<i;++v1)
{for(int v2=0;v2<combo.size();++v2)
{if(line[v1].output==combo[v2]){v3=v3+1;}}
if(v3==0){cout<<"Operand not declared ";return -1;}
v3=0;
}

//////////////////////check if output is not assigned reg////////////
v3=0;
for(int v1=0;v1<outputs.size();++v1)
{
    for(int v2=0;v2<i;++v2)
        if(line[v2].output==outputs[v1])
        {
            if((line[v2].input2).compare("0")==0)
            {}
            else
                 {cout<<"output register not mentioned ";return -1; }
        }
}

//////////////////////check if output is on left side of equation and input is on right side of equation//////////////////
v3=0;
for(int v1=0;v1<outputs.size();++v1)
{
    for(int v2=0;v2<i;++v2)
    {if((outputs[v1]==line[v2].input1) || (outputs[v1]==line[v2].input2) ||(outputs[v1]==line[v2].input3) ){v3=v3+1;}}
    if(v3==0){}else{cout<<"error output variable value is assigned to some literal ";return -1;}
    }
v3=0;
for(int v1=0;v1<inputs.size();++v1)
{
    for(int v2=0;v2<i;++v2)
    {if(inputs[v1]==line[v2].output){v3=v3+1;}}
    if(v3==0){}else{cout<<"input variable is assigned some value ";return -1;}
}




////////////////////////////////////////represent DAG///////////////////////
cout<<"DAG is "<<endl;
for(int i1=0;i1<i;i1++)
for(int j1=0;j1<i;j1++)
{
    if(line[i1].output==line[j1].input1)
    {z1[z3]=i1;
    z2[z3]=j1;
    z3=z3+1;
        getDAG(i1,j1);}
}

for(int i1=0;i1<i;i1++)
for(int j1=0;j1<i;j1++)
{
    if(line[i1].output==line[j1].input2)
    {
        z1[z3]=i1;
    z2[z3]=j1;
    z3=z3+1;
    getDAG(i1,j1);}
}

for(int i1=0;i1<i;i1++)
for(int j1=0;j1<i;j1++)
{
    if(line[i1].output==line[j1].input3)
    {
        z1[z3]=i1;
    z2[z3]=j1;
    z3=z3+1;
    getDAG(i1,j1);}
}//z3 will give total number of edges
/////find sources and destinations////
int c1=0;
int c2=0;


for(int z4=0;z4<i;z4++)
{for(int z5=0;z5<z3;z5++)
{
    if(z1[z5]==z4)
    {
    c1=c1+1;}
     if(z2[z5]==z4)
    {
    c2=c2+1;}

}


for(int b=0;b<z3;++b){//cout<<z1[b]<<endl;
}


if(c1==0){sink[i1]=z4;i1=i1+1;}
if(c2==0){source[i2]=z4;i2=i2+1;}
c1=0;
c2=0;
}
for(int b=0;b<i1;++b)
{//cout<<sink[b]<<endl;
}
//////////////numbers of nodes as reg////
for(int y=0;y<i;y++)
{if((line[y].operation)=="REG"){

                        reg[r]=y;
                  r=r+1;
                              }
}
////////////////////numbers of nodes as output/////
for(int y=0;y<i;y++)
{if((line[y].operation)=="OUTPUT"){

                        sinko[o]=y;
                  o=o+1;
                              }
}


/////////////////////////////////////////////////////////////
    }
            else {
                cout << "Unable to open file";return -1;
                 }
myfile1.close();

  ////////////////////////////////////////////////////tech_file_read/////////////////////////////////////////////////////////////////
  /////////////////////////////////////////////////////store componets names in file//////////////////////////////
    vector<string> tech_comp;
    string REG="REG";
    tech_comp.push_back(REG);
    string ADD32="ADD32";
    tech_comp.push_back(ADD32);
    string SUB32="SUB32";
    tech_comp.push_back(SUB32);
    string MUL32="MUL32";
    tech_comp.push_back(MUL32);
    string COMPLT="COMPLT";
    tech_comp.push_back(COMPLT);
    string COMPGT="COMPGT";
    tech_comp.push_back(COMPGT);
    string COMPEQ="COMPEQ";
    tech_comp.push_back(COMPEQ);
    string MUX2x1="MUX2x1";
    tech_comp.push_back(MUX2x1);
    string SHL="SHL";
    tech_comp.push_back(SHL);
    string SHR="SHR";
    tech_comp.push_back(SHR);

/////////////////////////////////////////////////////////////////actual read////////////////////////////////////////////////////////////////
    ifstream myfile2 (argv[2]);

    if (myfile2.is_open())
    {
      while(!myfile2.eof())
        {
            getline (myfile2,line1);

if(line1.empty())
            {}
            else
            {
                if((line1.find("//") != std::string::npos))
                 {if((line1.find("DELAY")!=std::string::npos))
                          {if((line1.find("ns")!=std::string::npos)){}
                          else{cout<<"delay is not mentioned in nanoseconds";return -1;}

                          }else{}
                 }
                else { if((line1.find_first_of(':'))!=-1){
                               vector<string> tokens1;
                               stringstream s(line1);
                                 string temp2;
                                 while(s>> temp2)
                                 {
                                    tokens1.push_back(temp2);

                                 }

                                 n_delay[k].type=tokens1[0];
                                 string k5=n_delay[k].type;
                                 n_delay[k].quantity=tokens1[2];
                                 string k1=n_delay[k].quantity;
                                 int k2=atoi(k1.c_str());
                                 n_delay[k].delay=tokens1[3];
                                 if((k5.compare("REG"))==0){delay_of_r=atof((n_delay[k].delay).c_str());}
                                        if(n_delay[k].type=="REG")
                                          {
                                               if(n_delay[k].quantity!="1")
                                               {cout<<"quantity of number of inputs to registers is wrong ";return -1;}
                                          }else if(n_delay[k].type=="MUX2x1")
                                                             {
                                                              if(n_delay[k].quantity!="3")
                                                              {cout<<"quantity of number of inputs to mux is wrong ";return -1;}
                                                            }
                                                            else
                                                                    {
                                                                      if(n_delay[k].quantity!="2")
                                                                      {cout<<"quantity of number of inputs to component is wrong ";return -1;}
                                                                    }
                                                                                                      //////////////////////////////////////////

                                                                    if(k2<1)
                                                                    {cout<<"number of components in line"<<k+1<<"are invalid";return -1;}
                                                                    else{}
                                                                    if(((n_delay[k].delay).find_first_of('.'))==-1)
                                                                    {cout<<"delay for line"<<k+1<<"is given in  non floating form";return -1;}
                                                                    else{}
                                                                    k3=0;
                                                                    k4=0;
                                                                    while(k3<10)

                                                                    {   string k6=tech_comp[k3];

                                                                        if((k5.compare(k6))==0)

                                                                        {
                                                                         k4=0;
                                                                        k4=k4+1;}
                                                                        else{}
                                                                       k3++;
                                                                    }

                                                                     if(k4==0){cout<<"Component names are invalid"<<endl;return -1;}

                                                                     k=k+1;//////////k is 1 more than number of strut elements
                                                                   //////////////////////////////////////////////////////

                                                           }
                             }
                }
            }


        }
    else{cout<<"enable to open file";return -1;}

            for(int i7=0;i7<10;i7++)
            {k4=0;
                for(int i8=0;i8<10;i8++)
            {if(((n_delay[i8].type).compare(n_delay[i7].type))==0)
            {k4=k4+1;}
            }
            if(k4>1){cout<<"components are mentioned more than one times";return -1;}
            }
myfile2.close();
if(k!=10)
{cout<<"number of components in technology file are not valid";return -1;}
//////////////////////////////////////////////////////////////////////////

for(int y1=0;y1<i;y1++)
{
for(int y2=0;y2<k;y2++)
if(((line[y1].operation).compare(n_delay[y2].type))==0)
{
   line[y1].delay=(n_delay[y2].delay);
   //cout<<line[y1].delay<<"BBB"<<endl;
}
else if(((line[y1].operation).compare("OUTPUT"))==0){ostringstream buff;
                                                          buff<<delay_of_r;
                                                          line[y1].delay=buff.str();
                                                      //cout<<line[y1].delay<<"BBB"<<endl;
                                                      }
}

//////////////////////////////////////////////////////////////////find path/////////////////////////////////////////////////////////////////////////////

for(int y1=0;y1<z3;y1++)
{
GRAPH[z1[y1]].push_back(z2[y1]);
}
//////////i/p to o/p max finding/////
for(int y2=0;y2<i2;y2++)
{
    for(int y1=0;y1<i1;y1++)
{
    max=findpaths(source[y2],sink[y1],i,z3,max);
}

}
///////////i/p to reg max finding////
if(R_FLAG==1)
{
for(int y=0;y<i;y++)
{if((line[y].operation)=="REG"){sinkr[v2]=y;sourcer[v2]=y;v2=v2+1;
                                }
}
for(int y2=0;y2<i2;y2++)
{
    for(int y1=0;y1<v2;y1++)
{max=findpaths(source[y2],sinkr[y1],i,z3,max);
}

}}
/////////////////////////reg to reg////////
if(R_FLAG==1)
{
for(int y2=0;y2<r;y2++)
{
  for(int y1=0;y1<r;y1++)
{max=findpaths(sourcer[y2],sinkr[y1],i,z3,max);
}

}}
/////////////reg to o/p/////////
if(R_FLAG==1)
{
for(int y2=0;y2<r;y2++)
{
for(int y1=0;y1<o;y1++)
{max=findpaths(sourcer[y2],sinko[y1],i,z3,max);
}

}

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
cout<<"critical path: "<<max<<" ns";


 return 0;

}
//////////////////////////////////functions//////////////////////////////////////
void display(vector<string> &pieces) ///////////vector is passed but used as pointer
{
    for(int i=0; i<pieces.size(); i++)
    {
string z=pieces[i];
        cout << z << endl;
    }
    cout << "\n" << endl;
}
///////////////////////////////////getDAG///////////////////////////////////////
void getDAG(int i1,int j1)
{
    cout<<i1<<"->"<<j1<<endl;
}
//////////////////////////////////////////////////////////find path//////////////////////////////////////////
float findpaths(int source ,int target ,int totalnode,int totaledge,float max)
{
    vector<int>path;
    vector<int>path1;
    path.push_back(source);
    queue<vector<int> >q;
    q.push(path);
    int flag=0;

    while(!q.empty())
    {
        path=q.front();
        q.pop();

        int last_nodeof_path=path[path.size()-1];
        if(last_nodeof_path==target)
        {flag=0;
            if(R_FLAG==1){for(int y=1;y<(path.size()-1);++y)
            {for(int y1=0;y1<r;++y1)
               if(path[y]==reg[y1]){flag=flag+1;}
               else{}
            }}
            if(flag==0)
        { //cout<<"the possible path is:: ";
            //print_path(path);
            //////////////////////////////////////////
            l2=0;
            for(int y1=0;y1<path.size();++y1)
            {float l1=atof((line[path[y1]].delay).c_str());
            l2=l2+l1;
            }
        }
        else{l2=0;}



        }
        ///////to check if arrived node is register. if yes then substract reg delay value once///////////
        for(int b=0;b<r;++b)
        {if(source==reg[b]){
            l2=l2-delay_of_r;}}



////////////////////////////////////////
  if(max<l2){max=l2;}

        for(int i=0;i<GRAPH[last_nodeof_path].size();++i)
        {
            if(node_present(GRAPH[last_nodeof_path][i],path))
            {

                vector<int>new_path(path.begin(),path.end());
                new_path.push_back(GRAPH[last_nodeof_path][i]);
                q.push(new_path);
            }
        }




    }
    return max;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline void print_path(vector<int>path)
{

    for(int i=0;i<path.size();++i)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool node_present(int node,vector<int>path)
{
    for(int i=0;i<path.size();++i)
    {
        if(path[i]==node)                      //to see if adjacency node is present in path
        return false;
    }
    return true;
}

//Clk, Rst,


