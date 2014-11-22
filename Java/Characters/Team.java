package Characters;
import java.util.ArrayList;

public class Team {
	private String name;
	private Color color; //Cores nomeadas no Enum
	private int win;
	private int lose;
	private int draw;
	private ArrayList<Character> characters;

	public Team(String Name, Color colour){
	name = Name;
	color = colour;
	win = 0;
	lose = 0;
	draw = 0;
	characters = new ArrayList<Character> (0);
	}

	public String getName(){
	return name;
	}

	public String getResults(){
	String Info = "Wins: " + win + " Losses: " + lose + " Draw: " + draw;
	return Info;
	}

	public String toString(){
	String Info = name + " " + color;
	return Info;
	}

	public void fight(Team EnemyTeam){
	ArrayList<Integer> rngTeam1 = new ArrayList<Integer> (4); //Deque de personagens desse time.
	ArrayList<Integer> rngTeam2 = new ArrayList<Integer> (4); //Deque de personagens do time adversario.
	ArrayList<Integer> TurnOrder = new ArrayList<Integer> (8); //Deque de ordem de quem luta com quem.
	for(int i=0; i<characters.size(); i++) rngTeam1.add(i); //Colocar ints em uma deque para evitar repeticao.
	for(int i=0; i<EnemyTeam.characters.size(); i++) rngTeam2.add(i);
	while((rngTeam1.size()>0)&&(rngTeam2.size()>0)){
		int i = (int) (Math.random()*rngTeam1.size()); //Puxar ints aleatoriamente para sortear os personagens.
		int j = rngTeam1.remove(i); //Apagar int ja selecionado.
		TurnOrder.add(j); //Empilhar turno.
		i = (int) (Math.random()*rngTeam2.size()); //Puxar ints aleatoriamente para sortear os personagens do outro time.
		j = rngTeam2.remove(i); //Apagar int ja selecionado.
		TurnOrder.add(j); //Empilhar turno.
		}
	while(TurnOrder.size()>1){
		int i = TurnOrder.remove(0);
		int j = TurnOrder.remove(0);
		characters.get(i).attack(EnemyTeam.characters.get(j)); //Um turno de batalha
		EnemyTeam.characters.get(j).attack(characters.get(i));
		}
	}

	public void resolveBattle(Team EnemyTeam){
	int AllyPoints = this.getPoints();
	int EnemyPoints = EnemyTeam.getPoints(); //Pegar media de HP
	if(AllyPoints < EnemyPoints) lose+=1; //Comparar media de HP
	else if(AllyPoints >EnemyPoints) win+=1;
	else draw+=1;
	}

	public void addChar(Character New){
	characters.add(New);
	}

	public void removeChar(int Num){
	if(Num < characters.size())
	characters.remove(Num);
	}

	public void removeChar(Character Chara){
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
	 if(characters.get(i).getName()==Chara.getName()){
	  characters.remove(i);
	  }
	}

	public Character searchChar(String Name){
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++)
	 if(characters.get(i).getName()==Name)
	  return characters.get(i);
	return null;
	}

	public int getPoints(){
	int Points = 0;
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++) Points += characters.get(i).getHP();
	return (Points/TeamSize);
	}

	public void PrintInfo(){ //Debug Print
	String S = " ";
	System.out.println("Team: " + color);
	System.out.println(getResults());
	int TeamSize = characters.size();
	for(int i=0; i<TeamSize; i++) characters.get(i).PrintInfo();
	System.out.println("");
	}

};
