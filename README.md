### Ronber Jonathan T. Prado - G01

### C PROGRAM
Vector Size | Execution Time (microseconds)  
2^20 | 6.700000  
2^24 | 98.000000  
2^28 | 1351.500000  

### C PROGRAM RATE OF INCREASE BY VECTOR SIZE
Vector Size | Execution Time (microseconds)  
2^20 to 2^24 | 14.62686567  
2^24 to 2^28 | 13.79081633  

### C PROGRAM RATE OF INCREASE VS x86 VS SIMD
PROGRAM (2^20 VECTOR) | Rate of Increase in Execution Time  
C to x86-64 | 0.5721392537  
C to SIMD | 0.1641791045  

### PROGRAM (2^24 VECTOR) | Rate of Increase in Execution Time
C to x86-64 | 0.543877551  
C to SIMD | 0.1894557857  

### PROGRAM (2^28 VECTOR) | Rate of Increase in Execution Time
C to x86-64 | 0.6300406955  
C to SIMD | 0.2237760511  

### ANALYSIS OF C PROGRAM
The C program was run thirty times, and the execution time increased by a factor of 13.791 to 14.627 when the vector size increased by a factor of 4. The rate of increase was calculated using the formula final execution time / initial execution time. The rate of increase in execution time of C to x86-64 is 0.544 to 0.630. On the other hand, for C to SIMD, the rate is increased by 0.164 to 0.224. Because the rate of increase in execution time is less than 1, it means that the C program is slower than both x86 and SIMD. This is due to overheads of the C language because it is a higher-level language compared to the low-level assembly language. There are some abstractions to make the code readable and the user does not directly access the memory registers which results in additional computing cost.  

### x86-64 PROGRAM
Vector Size | Execution Time (microseconds)  
2^20 | 3.833333  
2^24 | 53.300000  
2^28 | 851.500000  

### x86-64 PROGRAM RATE OF INCREASE BY VECTOR SIZE
Vector Size | Rate of Increase in Execution Time  
2^20 to 2^24 | 13.90434904  
2^24 to 2^28 | 15.97560976  

### x86-64 PROGRAM RATE OF INCREASE VS x86 VS SIMD
PROGRAM (2^20 VECTOR) | Rate of Increase in Execution Time  
x86-64 to C | 1.747826239  
x86-64 to SIMD | 0.2869565467  

### PROGRAM (2^24 VECTOR) | Rate of Increase in Execution Time
x86-64 to C | 1.838649156  
x86-64 to SIMD | 0.3483427205  

### PROGRAM (2^28 VECTOR) | Rate of Increase in Execution Time
x86-64 to C | 1.58719906  
x86-64 to SIMD | 0.2237760511  

### ANALYSIS OF x86-64 PROGRAM
The x86-64 program was run thirty times, and the execution time increased by a factor of 13.9 to 15.98 when the vector size increased by a factor of 4. The rate of increase was calculated using the formula final execution time / initial execution time. The rate of increase in execution time of x86-64 to C is 1.587 to 1.839. On the other hand, for x86-64 to SIMD, the rate is increased by 0.224 to 0.348. Based on the results, the x86 program is faster than the C program but slower than SIMD. This is due to x86 being a lower-level language than C that has more overheads which are discussed in the Analysis of C Program above. It is slower than the SIMD program because of the parallel computing feature of SIMD.  

### x86 SIMD PROGRAM
Vector Size | Execution Time (microseconds)  
2^20 | 1.100000  
2^24 | 18.566667  
2^28 | 302.433333  

### x86 SIMD PROGRAM RATE OF INCREASE BY VECTOR SIZE
Vector Size | Rate of Increase in Execution Time  
2^20 to 2^24 | 16.87878818  
2^24 to 2^28 | 16.28904816  

### x86 SIMD PROGRAM RATE OF INCREASE VS C VS x86
PROGRAM (2^20 VECTOR) | Rate of Increase in Execution Time  
SIMD to C | 6.090909091  
SIMD to x86-64 | 3.484848182  

PROGRAM (2^24 VECTOR) | Rate of Increase in Execution Time  
SIMD to C | 5.278276386  
SIMD to x86-64 | 2.870736035  

PROGRAM (2^28 VECTOR) | Rate of Increase in Execution Time  
SIMD to C | 4.468753449  
SIMD to x86-64 | 2.815496531  

### ANALYSIS OF x86 SIMD PROGRAM
The x86 SIMD program was run thirty times, and the execution time increased by a factor of 16.289 to 16.879 when the vector size increased by a factor of 4. The rate of increase was calculated using the formula final execution time / initial execution time. The rate of increase in execution time of SIMD to C is 4.469 to 6.091. On the other hand, for SIMD to x86-64, the rate is increased by 2.815 to 3.485. Based on the results, the SIMD program is faster than both the C program and x86-64 program. This is due to the feature of SIMD program wherein multiple operations are performed in parallel. It is faster than C because of fewer overheads and a lower-level assembly language. It is also faster than x86 because the operations were performed in parallel.  

### SCREENSHOT OF THE PROGRAM OUTPUT WITH CORRECTNESS CHECK (C)
![C - correctness output](https://github.com/jonaprado/stencil-project/assets/92654347/d06029db-c8c9-4a4f-8d8e-75c268a32992)

### SCREENSHOT OF THE PROGRAM OUTPUT INCLUDING CORRECTNESS CHECK (X86-64)

### SCREENSHOT OF THE PROGRAM OUTPUT INCLUDING CORRECTNESS CHECK (SIMD YMM REGISTER)

### SCREENSHOT OF THE PROGRAM OUTPUT INCLUDING CORRECTNESS CHECK (CUDA, OPTIONAL)


