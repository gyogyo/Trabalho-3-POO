package Characters;
import Items.*;
public abstract class Character {
      
//Atributos

	private String alias;
	private Inventory myitems;
	private int HP;
	private int MP;
	
	protected int XP;
	protected int strenght;
	protected int basespeed; //Membro adicionado, e o valor da velocidade do personagem sem modificadores de armadura.
	protected int speed; //Velocidade funcional.
	protected int dexterity;
	protected int constitution;    

//Metodos
	
	public Character(String Name){
	alias = Name;
	HP = 100;
	MP = 100;
	XP = 1;
	myitems = new Inventory();

	//Logica para os pontos: Ha 4 Rands() seguidos, que puxam de um total de 97 pontos cumulativos.
	//O algoritmo foi feito para que sempre ao menos sobre 1 ponto, para evitar a divisao por 0.
	//Desse modo, ha na verdade, 96 pontos disponiveis, ja que o minimo de cada um dos quatro atributos e 1.

	int limite = 97;
	strenght = (int) (Math.random()*limite)+1;
	limite -= (strenght-1);
	basespeed = speed = (int) (Math.random()*limite)+1;
	limite -= (speed-1);
	dexterity = (int) (Math.random()*limite)+1;
	limite -= (dexterity-1);
	constitution = limite;
	}

	//Getters
	public String getName(){
	return alias;
	}

	public int getHP(){
	return HP;
	}

	public int getMP(){
	return MP;
	}

	public Inventory getInventory(){
	return myitems;
	}

	public abstract void attack(Character Enemy);

	//Setters
	public void addXP(int Amount){
	if((XP+Amount)>99) XP = 100;
	else XP += Amount;
	}

	public void setStrenght(int Amount){
	if(Amount>0&&Amount<101) strenght = Amount;
	}

	public void setSpeed(int Amount){
	if(Amount>0&&Amount<101) speed = Amount;
	}

	public void setDexterity(int Amount){
	if(Amount>0&&Amount<101) dexterity = Amount;
	}

	public void setConstitution(int Amount){
	if(Amount>0&&Amount<101) constitution = Amount;
	}

	public void addHP(int Amount){
	if((HP+Amount)<0) HP = 0; //HP nao negativo.
	else HP += Amount;
	}

	public void addMP(int Amount){
	if((MP+Amount)<0) MP = 0; //MP nao negativo.
	else MP += Amount;
	}

	//Funcao Debug
	public void PrintInfo(){ //Debug Print
	System.out.println("Alias: " + alias);
	System.out.println("HP/XP/Str/Spd/Dex/Con: " + HP + " " + XP + " " + strenght + " " + speed + " " + dexterity + " " + constitution);
	myitems.PrintInfo();
	System.out.println("Atk/Def: " + getAttackPoints() + " " + getDefensePoints());
	}

	//Manipulacao de items e inventario
	public void getItem(Item New){
	myitems.insertItem(New);  //Colocar um item no inventario.
	}

	public void equipWeapon(Item Select){
	//Weapon Select2 = (Weapon) Select;
	//cout << Select2->getName() << " " << Select2->getRange() << endl; //Debug Print
	myitems.equipWeapon(Select/*2*/.getName());
	}

	public void equipArmor(Item Select){
	Armor Select2 = (Armor) Select; //Sabendo que eu vou apenas passar armaduras para essa funcao, uso esse cast.
	//cout << Select2->getName() << " " << Select2->getWeight() << endl; //Debug Print
	int x = (int) (basespeed*(Math.sqrt(Select2.getWeight())/10));
	setSpeed(x); //Formula estranha de velocidade que aumenta velocidade com armadura mais pesada.
	myitems.equipArmor(Select2.getName());
	}

	public void useItem(Item Use){
	if(myitems.searchItem(Use.getName())==null) return; //Se esse item estiver no inventorio
	else if(Use.getType()!=0){ //Health or Mana Potion
		Potion Pot = (Potion) Use;
		Pot.setOwner(this);  //Se colocar como usuario
		Pot.use(); //Usar pocao
		myitems.removeItem(Use.getName()); //Remover do inventorio
		}
	}

	//Calculo de batalha	
	protected int getDefensePoints(){
	int BaseDef = (int) (((constitution*5)+(dexterity*3)+(speed*2))/10);
	return (int) ((BaseDef+myitems.itemDefPts())*XP)/6;
	}

	protected int getAttackPoints(){
	int BaseAtk = (int) (((strenght*5)+(dexterity*3)+(speed*2))/10);
	return (int) ((BaseAtk+myitems.itemAtkPts())*XP)/2;
	}
};
