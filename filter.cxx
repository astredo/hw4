#include<fstream>
#include<string>

using namespace std;

void reading(double*, const int, const string);
void filter(double*, int);
void writing(double*, int, const string);

int main()
{
  const int n = 237;
  double* f = new double[n];
 
  const string input = "noisy.txt";
  const string output = "filtered.txt";
  
  reading(f, n, input);
  filter(f, n);
  writing(f, n, output);

  delete[] f;
  return(0);
}


void reading(double* f, const int n, const string input)
{
  ifstream in(input.c_str());
  
  for (int i = 0; i < n; ++i)
    {
      in >> f[i];
    }
 in.close();
}  


void filter(double* f, const int n)
{
  double fold = f[0];
  double f0 = f[0];
  
  f[0] = (f[n-1] + f[0] + f[1])/3.0;
  
  for(int i = 1; i < n - 1; i++)
    {
      double blub = f[i];
      f[i] = (fold + f[i] + f[i+1])/3.0;
      fold = blub;
    }
  
  f[n-1] = (fold + f[n-1] + f0)/3.0;
}


void writing(double* f, const int n, const string output)
{
  ofstream out(output.c_str());
  
  for(int i = 0; i < n; i++)
    {
      out << f[i] << endl;
    }
  out.close();
}
