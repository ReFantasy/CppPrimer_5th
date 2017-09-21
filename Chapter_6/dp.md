//矩阵链乘
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
//#include <stdexcept>
using namespace std;
double square(double x) { return x * x; }
class MatrixChain
{
public:
	MatrixChain(vector<int> m_Matrix)
	{
		Matrix = m_Matrix;
		n = m_Matrix.size() - 1;
		
		m = vector<vector<int>>(n+1, vector<int>(n+1, 0));
		path = vector<vector<int>>(n+1, vector<int>(n+1, 0));
	}
	void compute()
	{
		for (int l = 1; l < n; l++)
		{
			for (int i = 1; i <= (n - l); i++)
			{
				int j = i + l;
				m[i][j] = -1;
				for (int k = i; k < j; k++)
				{
					int q = m[i][k] + m[k + 1][j] + Matrix[i - 1] * Matrix[k] * Matrix[j];
					if (m[i][j] == -1 || q < m[i][j])
					{
						m[i][j] = q;
						path[i][j] = k;
					}
				}
			}
		}
	}

	void printResult(int L, int R)
	{
		if (L >= R)
			return;
		else
		{
			int k = path[L][R];
			cout << "A" << L << "," << "A" << R << ":" << k << endl;
			
			printResult(L, k);
			printResult(k + 1, R);
		}
    }
private:
	int n;
	vector<int> Matrix;
	vector<vector<int>> m;
	vector<vector<int>> path;
};
int main(int argc, char** argv)
{
	vector<int> matrix{ 30,35,15,5,10,20,25,15,145,15,26,6526,46,165,15,45,16,156,1465,156 };
	MatrixChain matrixChain(matrix);
	matrixChain.compute();
	matrixChain.printResult(1, matrix.size()-1);
}
