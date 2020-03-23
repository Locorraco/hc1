"""
    inflexion.py
    Copyright (C) 2020  Bruce Hiram Ginori Rodriguez
                        bruginrod@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""

#!/usr/bin/env python3

import matplotlib
import matplotlib.pyplot as plt
import numpy as np

# Data for plotting
with open("inflexion.dat") as file:  
    data = file.readlines() 

n_vector=[]
real_vector=[]
user_vector=[]
sys_vector=[]
derivative=[]
derivative2=[]

x0=x1=y0=y1=0.0

for line in data:
    if '#' not in line[0]:
        n,real,user,sys = line.split(' ')
        n_vector.append(int(n))
        real_vector.append(float(real))
        user_vector.append(float(user))
        sys_vector.append(float(sys))

for i in range(len(n_vector)-1):
    x0 = n_vector[i]
    x1 = n_vector[i+1]
    
    y0 = user_vector[i]
    y1 = user_vector[i+1]
    
    derivative.append((y1 - y0)/(x1 - x0))
    #y' = (y_1 - y_0)/(x_1 - x_0)
    
derivative.append(0.0)

for i in range(len(n_vector)-1):
    x0 = n_vector[i]
    x1 = n_vector[i+1]
    
    y0 = derivative[i]
    y1 = derivative[i+1]
    
    derivative2.append((y1 - y0)/(x1 - x0))
    #y' = (y_1 - y_0)/(x_1 - x_0)
    
derivative2.append(0.0)

fig, ax = plt.subplots()
ax.plot(n_vector, user_vector)
ax.plot(n_vector, derivative)
ax.plot(n_vector, derivative2)

ax.set(xlabel='numproc', ylabel='time [sec]',
       title='Inflection Point')
ax.grid()

#ax.set_yscale("log")

fig.savefig("inflexion.png")
plt.show()
