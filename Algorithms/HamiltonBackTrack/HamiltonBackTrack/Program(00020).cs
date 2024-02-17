using System;
using System.Collections.Generic;
using System.Text;

namespace HamiltonBackTrack
{
    class Program
    {
        static void Main(string[] args)
        {
            GetGraph();
            vertexIndex[0] = 1;
            Console.WriteLine("HamiltonianExpand : ");
            HamiltonianExpand(0);
            Console.WriteLine("Hamiltonian : ");
            Hamiltonian(0);
        }
        static public void Hamiltonian(int i)
        {
            int j = 0;

            if (Promising(i))
            {
                if (i == n - 1)
                    PrintArray();
                else 
                { 
                    for (j = 2; j <= n; j++) 
                    { 
                        vertexIndex[i + 1] = j;
                        Hamiltonian(i + 1);
                    }
                }
            }
        }
        static public void HamiltonianExpand(int i)
        {
            int j = 0;
            for (j = 0; j <= n; j++)
            {
                vertexIndex[i + 1] = j;
                if (Promising(i + 1))
                {
                    if (i == n - 2 )
                        PrintArray();
                    else
                    {
                        HamiltonianExpand(i + 1);
                    }
                }
            }
        }
        static public bool Promising(int i)
        {
            int j ;

            if (i == n - 1 && weight[vertexIndex[n - 1], vertexIndex[0] ] == 0)
                return false;
            else
            {
                if (i > 0 && weight[vertexIndex[i - 1] , vertexIndex[i] ] == 0)
                    return false;
                else
                {
                    j = 0;
                    while (j < i)
                    {
                        if (vertexIndex[i] == vertexIndex[j])
                            return false;
                        j++;
                    }
                }
            }
            return true;
        }
        static public void PrintArray()
        {
            Console.WriteLine();
            for (int i = 0;i< n;i++)
                Console.Write(vertexIndex[i]);
            Console.Write(vertexIndex[0]);
            Console.WriteLine();
        }
        static public void GetGraph()
        {
            Console.WriteLine("Enter Number of Vertices : ");
            n = Convert.ToInt16( Console.ReadLine());
            vertexIndex = new int [n];
            weight = new int [n + 1,n + 1];

            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    Console.Write("Enter weight of vertex :{0} to {1} : ",i , j);
                    weight[i, j] = Convert.ToInt16( Console.ReadLine());
                }
                Console.WriteLine();
            }
            for (int i = 1; i < n;i++ )
                weight[i,i] = 0;
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    weight[j, i] = weight[i, j];
            
        }
        static public int n;
        static public int[] vertexIndex;
        static public int[,] weight;
    }
}
