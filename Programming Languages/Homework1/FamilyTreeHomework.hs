module FamilyTreeHomework where

data Gender = Male | Female deriving (Show, Eq)
data Person = Person Gender String deriving (Show, Eq)
data FamilyTree = Empty | Family Person Person [FamilyTree] | Individual Person deriving (Show, Eq)

addchild        :: FamilyTree   -> Person -> FamilyTree
ischild         :: FamilyTree   -> Person -> Bool

childrenOf      :: FamilyTree   -> Person  -> [Person]
marryTo         :: FamilyTree   -> Person  -> Person -> FamilyTree

mother          :: FamilyTree   -> Person -> Maybe Person
brothers        :: FamilyTree   -> Person -> [Person]

-- DO NOT MODIFY ABOVE THIS LINE
-- Start Here

x = (Family(Person Male "John")(Person Female "Emily" ) [ Family ( Person Male "Peter" ) ( Person Female "Louis" ) [] , Family ( Person Male "Jackson" )( Person Female "Tina" ) [ Individual ( Person Male "Willie" ) , Individual ( Person Female "Carrie" ) ] , Individual ( Person Female "Amelia" ) , Individual( Person Female "Emma" ) ] )

---------------------------------- ISEMPTY ----------------------------------------------

isEmpty a
	| length a == 0 = True
	| otherwise = False

----------------------------------- GETMEMBERS -------------------------------------------

getMembers (Empty) = []
getMembers (Individual person) = []
getMembers (Family person1 person2 []) = []
getMembers (Family person1 person2 [(Individual person3)]) = [person3]
getMembers (Family person1 person2 [(Family person3 person4 family)]) = [person3] ++ [person4]
getMembers (Family person1 person2 ((Individual person3):left)) = [person3] ++ getMembers(Family person1 person2 left)
getMembers (Family person1 person2 ((Family person3 person4 family):left)) = [person3] ++ [person4] ++ getMembers(Family person1 person2 left)

------------------------------------- CHILDRENOF ------------------------------------------	

childrenOf (Empty) (Person givenGender givenName) = []
childrenOf (Individual person) (Person givenGender givenName) = []
childrenOf (Family person1 person2 []) (Person givenGender givenName) = []
childrenOf (Family (Person gender1 name1) (Person gender2 name2) ((Individual person3):left)) (Person givenGender givenName)
	| name1 == givenName || name2 == givenName = getMembers(Family (Person gender1 name1) (Person gender2 name2) ((Individual person3):left))
	| otherwise childrenOf (Family (Person gender1 name1) (Person gender2 name2) left) (Person givenGender givenName)

childrenOf (Family (Person gender1 name1) (Person gender2 name2) ((Family (Person gender3 name3) (Person gender4 name4) family):left)) (Person givenGender givenName)
	| name1 == givenName || name2 == givenName = getMembers(Family (Person gender1 name1) (Person gender2 name2) ((Family (Person gender3 name3) (Person gender4 name4) family):left))
	| otherwise childrenOf (Family (Person gender3 name3) (Person gender4 name4) family) (Person givenGender givenName) ++ 
											childrenOf(Family (Person gender1 name1) (Person gender2 name2) left) (Person givenGender givenName)

------------------------------------- ADDCHILD -------------------------------------------

addchild (Empty) (Person gender name) = Empty
addchild (Individual person) (Person gender name) = (Individual person)
addchild (Family person1 person2 family) (Person gender name) = (Family person1 person2 (family ++ [Individual (Person gender name)]))

--------------------------------------- ISCHILD -------------------------------------------

ischild (Empty) (Person gender name) = False
ischild (Individual person) (Person gender name) = False

ischild (Family (Person gender1 name1) (Person gender2 name2) ((Individual (Person gender3 name3)):(left))) (Person gender name)
	| name3 == name = True
	| isEmpty (left) == True = False
	| otherwise = ischild(Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name)
	
ischild (Family (Person gender1 name1) (Person gender2 name2) (  (Family (Person gender3 name3) (Person gender4 name4) family)  :left )) (Person gender name)
	| (name1 == name) = False
	| (name2 == name) = False
	| (name3 == name) = True
	| (name4 == name) = True
	| isEmpty (left) == True = False
	| otherwise = ischild (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name)	


---------------------------------- MOTHER ---------------------------------------------------

motherWithoutMaybe (Empty) (Person gender name) = []
motherWithoutMaybe (Individual person) (Person gender name) = []
motherWithoutMaybe (Family person1 person2 []) (Person gender name) = []	

motherWithoutMaybe (Family (Person gender1 name1) (Person gender2 name2) ((Individual (Person gender3 name3)):(left))) (Person gender name)
	| name == name3 && gender1 == Female = [Person gender1 name1]
	| name == name3 && gender2 == Female = [Person gender2 name2]
	| otherwise = motherWithoutMaybe (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) 

motherWithoutMaybe (Family (Person gender1 name1) (Person gender2 name2) ((Family (Person gender3 name3) (Person gender4 name4) family):(left))) (Person gender name)
	| name == name3 && gender1 == Female = [Person gender1 name1]
	| name == name3 && gender2 == Female = [Person gender2 name2]
	| name == name4 && gender1 == Female = [Person gender1 name1]
	| name == name4 && gender2 == Female = [Person gender2 name2]
	| otherwise = motherWithoutMaybe (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) ++ motherWithoutMaybe (Family (Person gender3 name3) (Person gender4 name4) (family)) (Person gender name)

mother family child
	| motherWithoutMaybe family child == [] = Nothing
	| otherwise = Just ((motherWithoutMaybe family child)!!0)

----------------------------- BROTHERS -------------------------------------------------------

findSons (Empty) (Person gender name) [Person mothergender mothername] = []
findSons (Individual person) (Person gender name) [Person mothergender mothername] = []
findSons (Family person1 person2 []) (Person gender name) [Person mothergender mothername] = []

findSons (Family (Person gender1 name1) (Person gender2 name2) ((Individual (Person gender3 name3)):(left))) (Person gender name) [Person mothergender mothername]
	| (mothername == name1) && (name /= name3) && (gender3 == Male) = [Person gender3 name3] ++ findSons (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) [Person mothergender mothername]
	| (mothername == name2) && (name /= name3) && (gender3 == Male) = [Person gender3 name3] ++ findSons (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) [Person mothergender mothername]
	| otherwise = findSons (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) [Person mothergender mothername]


findSons (Family (Person gender1 name1) (Person gender2 name2) ((Family (Person gender3 name3) (Person gender4 name4) family):(left))) (Person gender name) [Person mothergender mothername]
	| ((name1 ==name) || (name2 == name)) = []	
	| (mothername == name1 || mothername == name2) && (name /= name3) && (name /= name4) && (gender3 == Male) = [Person gender3 name3] ++ findSons (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) [Person mothergender mothername]
	| (mothername == name1 || mothername == name2) && (name /= name3) && (name /= name4) && (gender4 == Male) = [Person gender4 name4] ++ findSons (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) [Person mothergender mothername]
	| otherwise = findSons (Family (Person gender1 name1) (Person gender2 name2) (left)) (Person gender name) [Person mothergender mothername] ++ findSons (Family (Person gender3 name3) (Person gender4 name4) (family)) (Person gender name) [Person mothergender mothername]


brothers family sibling
	| motherWithoutMaybe family sibling == [] = []
	| findSons (family) (sibling) (motherWithoutMaybe family sibling) == [] = []
	| otherwise = findSons (family) (sibling) (motherWithoutMaybe (family) (sibling))

--------------------------- MARRYTO ---------------------------------------------------------

marryTo (Empty) person1 person2 = Empty
marryTo (Individual (Person gender name)) (Person marryGender marryName) (Person marryGender2 marryName2)
	| marryName == name && marryGender /= marryGender2 = Family (Person gender name) (Person marryGender2 marryName2) []
	| otherwise = (Individual (Person gender name))

marryTo (Family (Person gender1 name1) (Person gender2 name2) ((Individual (Person gender3 name3)):(left))) (Person marryGender marryName) (Person marryGender2 marryName2)
	| marryName == name1 && marryGender /= marryGender2 = (Family (Person gender1 name1) (Person marryGender2 marryName2) ((Individual (Person gender3 name3)):(left))) (Person marryGender marryName) (Person marryGender2 marryName2)
 	| marryName == name2 && marryGender /= marryGender2 = (Family (Person marryGender2 marryName2) (Person gender2 name2) ((Individual (Person gender3 name3)):(left))) (Person marryGender marryName) (Person marryGender2 marryName2)
 	|


	
	
	
	
	
	
		
	
