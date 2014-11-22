package Items;
import java.util.*;

public class Inventory {
//Atributos
	private int spaces;
	private double gold;
	private ArrayList<AbstractMap.SimpleEntry<Item,Boolean>> items; //Java nao tem pair, mas podemos usar AbstractMap
	private int armorequip; //Variaveis para os dados de equipamento
	private int[] weaponequip; //Quais armas estao equipadas

//Metodos
	public Inventory(){
	spaces = 10;
	gold = 0.0;
	armorequip = -1; //Nada equipado
	weaponequip = new int[2];
	weaponequip[0] = -1;
	weaponequip[1] = -1;
	items = new ArrayList<AbstractMap.SimpleEntry<Item,Boolean>> (0);
	}

	//Getters
	public double getTotalGold(){
	return gold;
	}

	public int getAvailableSpace(){
	return spaces; //Retorna espacos vazios no vector.
	}

	//Setters
	public void spendGold(double Amount){
	if((gold - Amount)>=0) gold -= Amount; //Gold nao negativo.
	}

	public void earnGold(double Amount){
	gold += Amount;
	}

	//Enquanto o atributo spaces indica o espaco disponivel, setSpaces(int) altera o espaco absoluto.
	//Se for colocado um numero menor que o tamanho atual, os items extras serao forcadamente removidos.
	public void setSpaces(int Amount){
	if(Amount>0){
		if(Amount>items.size()){
			items.ensureCapacity(Amount);
			spaces = (items.size())-Amount;
			 }
		else {
			while(items.size()>Amount){
				items.remove(items.size()-1);
				}
			items.trimToSize();
			spaces = 0;
			}
		}
	}

	//Operacoes com items
	//Retorna UM item com o devido nome.
	public Item searchItem(String Name){
	      int InvSize = items.size();
	      for(int i=0; i<InvSize; i++)
		 if(items.get(i).getKey().getName()==Name)
		  return items.get(i).getKey();
	      return null;
	}

	//Retorno de posicao absoluta.
	public Item searchItem(int Num){
	      if(Num < items.size()) return items.get(Num).getKey();
	      return null;
	}
	//Insercao ao final do inventario.
	public void insertItem(Item New){
	AbstractMap.SimpleEntry<Item,Boolean> NewMap = new AbstractMap.SimpleEntry<Item,Boolean> (New,false);
	      if(spaces>0){
		 items.add(NewMap);
		 spaces--;
		 }
	}
	//Remove TODOS os items de mesmo nome.
	public void removeItem(String Name){
		int InvSize = items.size();
		for(int i=0; i<InvSize; i++)
			if(items.get(i).getKey().getName()==Name){
			items.remove(i);
			spaces++;
			}
	}
	//Remove o item com a posicao absoluta.
	public void removeItem(int Num){
		if(Num < items.size()){
			items.remove(Num);
			spaces++;
		}
	}

	//Retorna soma total de ataque.
	public int itemAtkPts(){
		int InvSize = items.size();
		int Total=0;
		for(int i=0; i<InvSize; i++)
			if(items.get(i).getValue()==true)
			Total += items.get(i).getKey().getAttackPts();
		return Total;
	}
	//Retorna soma total de defesa.
	public int itemDefPts(){
		int InvSize = items.size();
		int Total=0;
		for(int i=0; i<InvSize; i++)
			if(items.get(i).getValue()==true)
			Total += items.get(i).getKey().getDefensePts();
		return Total;
	}

	public void PrintInfo(){ //Debug Print
	String S = " ";
	System.out.println("Inventory: ");
	int InvSize = items.size();
	for(int i=0; i<InvSize; i++){
		System.out.println("Item " + i + " : " + items.get(i).getKey().getName());
		System.out.println("Price/Atk/Def/Equip : " +
		items.get(i).getKey().getPrice() +S+ items.get(i).getKey().getAttackPts() +S+
		items.get(i).getKey().getDefensePts() +S+ items.get(i).getValue());
		System.out.println("Ataque/Defesa dos items equipados: " + itemAtkPts() +S+ itemDefPts());
		}
	}

	public void equipWeapon(String Select){ //Funcao para equipar arma e armadura no personagem.
	int InvSize = items.size();
	int N = -1;
	for(int i=0; i<InvSize; i++)
	 if(items.get(i).getKey().getName()==Select) //Procurar arma no inventario
	  N = i;
	if(weaponequip[1]!=-1) items.get(weaponequip[1]).setValue(false); //Se tinha uma arma no segundo slot, desequipar.
	if(weaponequip[0]!=-1) weaponequip[1] = weaponequip[0]; //Jogar arma do primeiro slot pro segundo.
	if(N!=-1) items.get(N).setValue(true); //Se esta equipando uma arma valida, settar bool.
	weaponequip[0] = N; //Colocar novo equipamento no primeiro slot. Esse algoritmo fica fazendo ciclos com as armas que sao equipadas.
	}

	public void equipArmor(String Select){
	int InvSize = items.size();
	int N = -1;
	for(int i=0; i<InvSize; i++)
	 if(items.get(i).getKey().getName()==Select) //Procurar armadura no inventario
	  N = i;
	if(armorequip!=-1) items.get(armorequip).setValue(false); //Se tinha armadura equipada, tirar.
	if(N!=-1) items.get(N).setValue(true); //Equipar nova armadura.
	armorequip = N; //Colocar equip no slot.
	}

};
