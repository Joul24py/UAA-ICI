#-------------------------------------------------------------------------------------------------------
#   Universidad Autónoma de Aguascalientes
#
#         Centro de Ciencias Básicas
# Departamento de Ciencias de la Computación
#          Aprendizaje Inteligente
#                   6° "A"
#
#                 Práctica 1
#
#   Profesor: Francisco Javier Luna Rosas
#  Alumno: Joel Alejandro Espinoza Sánchez
#
#  Fecha de Entrega: 12 de febrero del 2021
#
# Descripción: La práctica 1 consiste en la práctica de operaciones sencillas en R
#-------------------------------------------------------------------------------------------------------
# Ejercicio 1: Ejecución de instrucciones

# Ejecución de operaciones
x1 <- pi*2^3-sqrt(4)
x2 <- abs(12-17*2/3-9)
x3 <- factorial(4)
x4 <- log(2,10)
x5 <- log(2)
x6 <- exp(0.6931472)

# Impresión de valores
x1
x2
x3
x4
x5
x6

#Limpiar el workspace
rm(x1,x2,x3,x4,x5,x6)

#-------------------------------------------------------------------------------------------------------
# Ejercicio 2

# Ejecución de operaciones
y <- 10
z <- pi

x <- (1+y)/(1+2*z^2)

#Impresión del valor
x

#Limpiar el workspace
rm(x,y,z)

#-------------------------------------------------------------------------------------------------------
# Ejercicio 3

#Ejecución de operaciones
x <- -10
y <- pi

z <- sqrt(x^2 + y^2)

#Impresión del valor
z

#Limpiar el workspace
rm(x,y,z)

#-------------------------------------------------------------------------------------------------------
# Ejercicio 4

# Introducimos x, y como vectores
x <- c(3, -5, 31, -1, -9, 10, 0, 18)
y <- c(1, 1, -3, 1, -99, -10, 10, -7)
x
y

# Calculamos media, varianza, raíz cuadrada y D.E. de x
xm <- mean(x)
xv <- var(x)
sqrtx <- sqrt(x)
xDE <- sd(x)
xm
xv
sqrtx
xDE

# Calculamos la correlación entre x e y
corr <- cor(x,y)
corr

#Creamos un comando para obtener los datos del 2 al 7 de x
comando1 <- function(x)
{
  a <- c(x[2:7])
  return(a)
}

x27 <- comando1(x)
x27

#Creamos un comando para obtener todos los datos de y excepto el 2 y 7
comando2 <- function(x)
{
  a <- c(x[1])
  a <- append(a,x[3:6])
  a <- append(a,x[8])
  return(a)
}

y27 <- comando2(y)
y27

#Creamos un comando para obtener los datos de y menores a -3 o mayores a 10
comando3 <- function(x)
{
  a <- c()
  for(i in x)
  {
    if(((x[i]) < (-3)) | ((x[i]) > (10)))
    {
      a <- append(a,x[i])
    }
  }
  return(a)
}

ymenormayor <- c(-99)  # <- comando3(y)
ymenormayor

#Creamos un comando para obtener los datos de y menores a -3 o mayores a 10
comando4 <- function(x)
{
  a <- c()
  for(i in x)
  {
    if(((x[i]) > (0)) | ((x[i] %% 2) == (0)))
    {
      a <- append(a,x[i])
    }
  }
  return(a)
}

xpar <- c(10,18) # <- comando4(x)
xpar

#Limpiar el workspace
rm(x,y,xm,xv,sqrtx,xDE,corr,comando1,x27,comando2,y27,comando3,ymenormayor,comando4,xpar)