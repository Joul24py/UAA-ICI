  
  
                    #Universidad autónoma de Aguascalientes
                         #Centro de ciencias básicas
                 #Departamento de ciencias de la computación
                           #Aprendizaje inteligente
                                    #6°A


                      #DR. FRANCISCO JAVIER LUNA ROSAS
                    
                      #Joel Alejandro Espinoza Sánchez
                            #Dariana Gómez Garza
                     #Fernando Francisco González Arenas

#***********************************neurona OR***********************
  
  neuronaOR<-function(w1,w2,teta){
    
    
    x1 <- c(0, 0, 1, 1)
    x2 <- c(0, 1, 0, 1)
    or <- c(0, 1, 1, 1)
    
    tablaOR<- matrix(c(x1, x2, or),
                     nrow = 4,
                     ncol = 3)
    
    colnames(tablaOR) <- c('x1', 'x2', 'OR')
    tablaOR
    
    
    for (x in 0:4) 
    {
      n <-w1*x1[x] + w2*x2[x]
      if(!is.null (n >= teta))
      {
        a <- 1
      }else 
      {
        a <- 0
      }
      
      if(!is.null (a!= or[x])) returnValue (0)
      
    }
    returnValue (1)
    
  }
  
  
  repeat{
    w1<-runif(1, min=-2, max=2)
    w2<-runif(1, min=-2, max=2)
    teta<-runif(1, min=-2, max=2)
    
    w1
    w2
    teta
    
    
    if(neuronaOR(w1,w2,teta)!=0){
      break
    }
  }
  
  #resultados neurona OR:
  tablaOR
  w1
  w2
  teta
  #***********************************neurona AND***********************
  
  neuronaAND <- function(w1,w2,teta){
    
    x1 <- c(0, 0, 1, 1)
    x2 <- c(0, 1, 0, 1)
    and <- c(0, 0, 0, 1)
    
    tablaAND<- matrix(c(x1, x2, and),
                      nrow = 4,
                      ncol = 3)
    
    colnames(tablaAND) <- c('x1', 'x2', 'AND')
    tablaAND
    
    
    for (x in 0:4) 
    {
      n <-w1*x1[x] + w2*x2[x]
      if(!is.null (n >= teta))
      {
        a <- 1
      }else 
      {
        a <- 0
      }
      
      if(!is.null (a!= and[x])) returnValue (0)
      
    }
    returnValue (1)
  }  
  
  
  w1<-0
  w2<-0
  teta<-0
  
  repeat{
    w1<-runif(1, min=-2, max=2)
    w2<-runif(1, min=-2, max=2)
    teta<-runif(1, min=-2, max=2)
    
    
  
    
    if(neuronaAND(w1,w2,teta)!=0){
      break
    }
  }
  
  
  
  #resultados neurona AND:
  tablaAND
  w1
  w2
  teta
  
  
  #***********************************neurona AND negado***********************
  
  neuronaANDnegado<-function(w1,w2,teta){
    
    x1 <- c(0, 0, 1, 1)
    x2 <- c(0, 1, 0, 1)
    andnegado <- c(1, 1, 1, 0)
    
    
    tablaANDnegado<- matrix(c(x1, x2, andnegado),
                            nrow = 4,
                            ncol = 3)
    
    colnames(tablaANDnegado) <- c('x1', 'x2', 'ANDnegado')
    tablaANDnegado
    
    a <- 0
    
    for (x in 0:4) 
    {
      n <-w1*x1[x] + w2*x2[x]
      
      
      if(!is.null (n >= teta))
      {
        a <- 1
      }else 
      {
        a <- 0
      }
      
      
      if(!is.null (a!= andnegado[x])) returnValue (0)
      break
      
    }
    returnValue (1)
    
  }
  

  w1<-0
  w2<-0
  teta<-0
  
  
  repeat{
    w1<-runif(1, min=-2, max=2)
    w2<-runif(1, min=-2, max=2)
    teta<-runif(1, min=-2, max=2)
    
  
    
    if(neuronaANDnegado(w1,w2,teta)!=0){
      break
    }
  }
  
  
  #resultados neurona AND negado:
  tablaANDnegado
  w1
  w2
  teta
  
