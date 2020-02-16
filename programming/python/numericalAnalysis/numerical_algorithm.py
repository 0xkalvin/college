

'''

System of equations

Gauss

/* Applying Gauss Elimination */
	 for(i=1;i<=n-1;i++)
	 {
		  if(a[i][i] == 0.0)
		  {
			   printf("Mathematical Error!");
			   exit(0);
		  }
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = a[j][i]/a[i][i];
			   
			   for(k=1;k<=n+1;k++)
			   {
			  		a[j][k] = a[j][k] - ratio*a[i][k];
			   }
		  }
	 }

'''


#matrix = [[10, -7, 3], [-6, 8, 4], [2, 6, 9]]
matrix = [[10, -7, 3, 5], [-6, 8, 4, 7], [2, 6, 9, -1]]

def upper_triangular_matrix_solution(matrix):
    """ Returns the solution to an upper triangular matrix """

    # matrix length is the number of lines 
    size = len(matrix)


    result = [0 for i in range(size)]

    for i in range(size - 1, -1, -1):
        
        result[i] = matrix[i][size] / matrix[i][i]
        
        for j in range(i - 1, -1, -1):
            
            matrix[j][size] -= matrix[j][i] * result[i]
    
    return result

def pivotamento(m):
    n = len(m) 

    for i in range(1, n + 1):


        for j in range(1, n + 1):

            if j != i:

                ratio = m[j][i] / m[i][i]

                for k in range(1, n + 1):

                    m[j][k] = m[j][k] - ratio * m[i][k]


def gauss1(A):
  n = len(A)
  
  for i in range(0, n):
    #Search for maximum in this column
    maxE1 = abs(A[i][i])
    maxRow = i
    for k in range(i+1, n):
      #compares rows, first row can't start with zero
      if abs(A[k][i]) < maxE1 or maxE1 == 0: 
        maxE1 = abs(A[k][i])
        maxRow = k
    
    #Swap maximum row with current row (column by column)
    for k in range(i, n+1):
      tmp = A[maxRow][k]
      A[maxRow][k] = A[i][k]
      A[i][k] = tmp
    
    #Make all rows below this one 0 in current column
    for k in range(i+1, n):
      c = -A[k][i]/A[i][i]
      for j in range(i, n+1):
        if i == j:
          A[k][j] = 0
        else:
          A[k][j] += c * A[i][j]
  
    #Print echelon matrix
    print("Echelon Matrix:\t")
    print(A)
        
    #Solve equation Ax = b for echelon matrix
    x = [0 for i in range(n)]
    for i in range(n - 1, -1, -1):
        #there is no solution
        if A[i][i] == 0:
            return [0 for i in range(n)]
        #normal solution
        else:
            x[i] = A[i][n]/A[i][i]
            for k in range(i-1, -1, -1):
                A[k][n] -= A[k][i]*x[i]
    
    return x
 
print(gauss1(matrix))


#print(upper_triangular_matrix_solution(matrix))

