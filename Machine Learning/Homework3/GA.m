%***************************************************************************************************

1 ;  # Prevent Octave from thinking that this is a function file

%***************************************************************************************************

more  off ;
clear all ;
clc       ;

%***************************************************************************************************

global h =    5    ;  % Image height
global w =    5    ;  % Image width
global p =   10    ;  % Population size
global r =    0.90 ;  % Mutation probability
global t =    0.95 ;  % Acceptable rate of fitness
global f = 9999    ;  % Maximum populations

%---------------------------------------------------------------------------------------------------

global s = h * w   ;  % Image size in pixels
global m = s       ;  % Maximum possible fitness value

%***************************************************************************************************

% image  : an h x w rectangular matrix
% vector : a column vector of size s

function vector = imageToVector ( image )

  global s ;

  vector = reshape( image , s , 1 ) ;

endfunction

%***************************************************************************************************

% vector : a column vector of size s
% image  : an h x w rectangular matrix

function image = vectorToImage ( vector )

  global h w ;

  image = reshape( vector , h , w ) ;

endfunction

%***************************************************************************************************

% cumulativeDistribution : a row vector of size p with cumulative probabilities (last entry is 1.0)
% index                  : index, selected using fitness proportionate (roulette wheel) selection

function index = rouletteWheelSelect ( cumulativeDistribution )

  global p ;

  index = 1      ;
  value = rand() ;

  for i = 1 : p

    if ( cumulativeDistribution( 1 , i ) >= value )

      index = i ;
      break     ;

    endif

  endfor

endfunction

%***************************************************************************************************

% Performs single-point crossover on two column vectors (parents)
% Result is two column vectors (offsprings)

function [ child1 , child2 ] = crossover ( parent1 , parent2 )

  global s ;

  splitPoint = randi( s - 1 ) ;

  child1(1            : splitPoint , 1) = parent1(1            : splitPoint , 1) ;
  child1(splitPoint+1 : s          , 1) = parent2(splitPoint+1 : s          , 1) ;

  child2(1            : splitPoint , 1) = parent2(1            : splitPoint , 1) ;
  child2(splitPoint+1 : s          , 1) = parent1(splitPoint+1 : s          , 1) ;

endfunction

%***************************************************************************************************

% Performs two-point crossover on two column vectors (parents)
% Result is two column vectors (offsprings)

function [ child1 , child2 ] = crossover2 ( parent1 , parent2 )

  global s ;

  splitPoint1 =               randi( s - 2           ) ;
  splitPoint2 = splitPoint1 + randi( s - splitPoint1 ) ;

  child1( : , 1 ) = parent1( : , 1 ) ;
  child2( : , 1 ) = parent2( : , 1 ) ;

  child1( splitPoint1 : splitPoint2 , 1 ) = parent2( splitPoint1 : splitPoint2 , 1 ) ;
  child2( splitPoint1 : splitPoint2 , 1 ) = parent1( splitPoint1 : splitPoint2 , 1 ) ;

endfunction

%***************************************************************************************************

% vector : a column vector of size s
% Result is another column vector of size s with one randomly mutated entry

function mutated = mutate ( vector )

  global s ;

  mutationPoint = randi( s ) ;

  mutated( :             , 1 ) = vector( : , 1 ) ;
  mutated( mutationPoint , 1 ) = rand()          ;

endfunction

%***************************************************************************************************

% vector : a column vector of size s
% value  : fitness score between 0 and m

function value = fitness ( vector )

  global h w s ;

  f = 0 ;
  for p = 0 : (s-1)
    f += abs(vector(p+1,1)-(sin((sqrt((1+floor(p/h)-(w/2))^2+(-(1+mod(p,h)-(h/2)))^2)  / ...
         sqrt((w/2)^2+(h/2)^2))^0.6*25.13274122872)+10*(abs(atan2((-(1+mod(p,h)-(h/2))), ...
         (1+floor(p/h)-(w/2)))*57.295779513)/180))/11) ;
  endfor
  value = (s-f) ;

endfunction

%***************************************************************************************************

% populationSize        : number of individuals in the population
% mutationProbability   : probability of applying mutation to each offspring
% acceptableFitnessRate : stopping criterion (if fitness reaches this rate * m, training can stop)
% maximumPopulations    : stopping criterion (if iteration count exceeds this, training can stop)
% bestIndividual        : a column vector of size s
% fitnessHistory        : a row vector that keeps maximum fitness of each population in training

function [ bestIndividual , fitnessHistory ] = geneticAlgorithm ( populationSize        , ...
                                                                  mutationProbability   , ...
                                                                  acceptableFitnessRate , ...
                                                                  maximumPopulations    )
  global h w s m ;

  populationNo = 1                          ;
  population   = rand( s , populationSize ) ;  % Initial population




  %
  %
  % TODO
  %
  % JUST COMPLETE THIS FUNCTION IMPLEMENTATION !
  %
  % YOU MAY ADD HELPER FUNCTIONS BELOW IF YOU NEED !
  %

  fitnessHistory = [];
  fitnessArray = [];
  
  while true,
  
    if populationNo > maximumPopulations,
      break;
    end;
    
    newPopulation = [];
    populationNo = populationNo + 1;
    cumulativeFitnessArray = [];
    totalFitness = 0;
  
    %fitness array
    for i = 1:populationSize,
      currentFitness = fitness(population(1:rows(population), i));
      totalFitness = totalFitness + currentFitness;
      fitnessArray(1,i)=currentFitness;
    end; 
    
    %disp(fitnessArray);
    fitnessHistory(1,columns(fitnessHistory) + 1) = max(fitnessArray);
    
    %cumulative fitness
    numerator = 0;
    for i = 1:populationSize,
      numerator = fitnessArray(1,i);
      j = 1;
      while j < i-1,
        numerator = numerator + fitnessArray(1,j);
        j = j + 1;
      end;
      numerator = numerator / totalFitness; 
      cumulativeFitnessArray(1,i) = numerator;
    end; 
    
    %first max
    maxFitness1 = max(fitnessArray);
    disp(maxFitness1);
    maxIndex1 = 0;
    
    %second max
    maxFitness2 = 0;
    maxIndex2 = 0;
    for i = 1:populationSize,
      if fitnessArray(1,i) > maxFitness2 && fitnessArray(1,i) != maxFitness1,
        maxFitness2 = fitnessArray(1,i);
        maxIndex2 = i;
      end;
      if fitnessArray(1,i) == maxFitness1,
        maxIndex1 = i;
      end;
    end;
    
    %put two bests into new population
    newPopulation(1:rows(population),1)=population(1:rows(population),maxIndex1);
    newPopulation(1:rows(population),2)=population(1:rows(population),maxIndex2);
    
    %treshold break
    bestIndividual = population(1:rows(population),maxIndex1);
    if maxFitness1 >= m * acceptableFitnessRate,
      break;
    end;
    
    %first min
    minFitness1 = min(fitnessArray);
    minIndex1 = 0;
    
    %second min
    minFitness2 = 999999999;
    minIndex2 = 0;
    for i=1:populationSize,
      if fitnessArray(1,i) < minFitness2 && fitnessArray(1,i) != minFitness1,
        minFitness2 = fitnessArray(1,i);
        minIndex2 = i;
      end;
      if fitnessArray(1,i) == minFitness1,
        minIndex1 = i;
      end;
    end;

    %crossover between 8 bests 
    for i = 1:((populationSize-2)/2)
      while true,        
        index1 = rouletteWheelSelect(cumulativeFitnessArray);
        if index1 != minIndex1 && index1 != minIndex2,
          break
        end;
      end;
      
      while true,
        index2 = rouletteWheelSelect(cumulativeFitnessArray);
        if index2 != index1 && index2 != minIndex1 && index2 && minIndex2,
          break;
        end;
      end;
      
      crossoverPop1 = population(1:rows(population),index1);
      crossoverPop2 = population(1:rows(population),index2);
      [crossoverResult1, crossoverResult2] = crossover(crossoverPop1,crossoverPop2);
      newPopulation(1:rows(newPopulation),columns(newPopulation)+1) = crossoverResult1;
      newPopulation(1:rows(newPopulation),columns(newPopulation)+1) = crossoverResult2;
    end;
    
    %mutation between worst 8
    for i = 1:populationSize,
      mutationRandom = randi(10);
      if  i != maxIndex1 && i != maxIndex2 && mutationRandom < mutationProbability * 10,
        newPopulation(1:rows(newPopulation),i) = mutate(newPopulation(1:rows(newPopulation),i));
      end;
    end;
    
    %update population with Ps
    population = newPopulation;
    
  end;


endfunction

%***************************************************************************************************

% Main part of the script

figure(1) ;  clf ;

[ bestIndividual , fitnessHistory ] = geneticAlgorithm( p , r , t , f ) ;

bestImage = vectorToImage( bestIndividual ) ;

imshow ( bestImage                ) ;
imwrite( bestImage , "Result.jpg" ) ;

figure(2) ;  clf ;

plot  ( fitnessHistory , "r" ) ;  grid on ;
xlabel( "Populations"        ) ;
ylabel( "Maximum Fitness"    ) ;

print -djpg "Fitness.jpg" ;

%***************************************************************************************************

