#include<string>
#include<iostream>
#include<cstdlib>
#include<stdexcept>
class GameEntry{
    public:
        GameEntry(const std::string& name = "", int n = -1);
        std::string getName() const;
        int getScore() const;
        void display();
    protected:
    private:
        std::string name;
        int score;
};
GameEntry::GameEntry(const std::string& name , int n ): name(name), score(n){};
std::string GameEntry::getName() const{
    return this->name;
}
int GameEntry::getScore()const{
    return this->score;
}
void GameEntry::display(){
    std::cout<<"Name      --      |"<<this->getName()<<"|"<<std::endl;
        std::cout<<"Score      --      |"<<this->getScore()<<"|"<<std::endl;
        std::cout<<"----------------------------------|"<<std::endl;
}
class Score{
    public:
        Score(int n = 10);
        ~Score();
        void add(const GameEntry& e);
        GameEntry remove(int i);
        void display()const;
    protected:
    private:
        int max_entries;
        int num_entries;
        GameEntry* entries;
};
Score::Score(int n): max_entries(n), num_entries(0){
    entries = new GameEntry[max_entries];
};
Score::~Score(){
    delete[] entries;
};
void Score::display()const{
    int max = this->num_entries;
    int count = 0;
    while(count<max){
        std::cout<<"Name      --      |"<<this->entries[count].getName()<<"|"<<std::endl;
        std::cout<<"Score      --      |"<<this->entries[count].getScore()<<"|"<<std::endl;
        std::cout<<"----------------------------------|"<<std::endl;
        count++;
    }
}
void Score::add(const GameEntry& e){
    /*Insert game entry e into the collection of high scores. 
    If this causes the number of entries to exceed maxEntries, the smallest is removed.*/
    int newScore = e.getScore();
    //when entry list is full, and we get a new entry which is less than the least score in our entry, we dont add it
    if (this->num_entries==this->max_entries){
        if(newScore<=this->entries[num_entries-1].getScore()){
            std::cout<<"The score is very less for the score char."<<std::endl;
            return;
        }
    }
    //now we have to add scores in descending order, for that, we have to see where new entry inserts, and move all smaller ones to right
    num_entries++;
    int i = num_entries-2; //i denotes at the lowest score in the chart rn
    while(i>=0 && e.getScore()>this->entries[i].getScore()) {//as long as the new score is greater than the score denoted by i
        this->entries[i+1] = this->entries[i];   //the entry at i will be moved to i+1
        i--; //i is subtracted to see if the entry to the left of the entry we just moves is greatre than the new score or not
        //if not the loop continues
    }
    //the loop exits with i at the entry which is just greater than new score, and a space next to it which is pseudo-empty
    this->entries[i+1] = e;
}
GameEntry Score::remove(int i){
    /*
    Remove and return the game entry e at index i in the entries array. 
    If index i is outside the bounds of the entries array, then this function throws an exception; otherwise, 
    the entries array is updated to remove the ob- ject at index i and all objects previously stored at indices 
    higher than i are “shifted left” to fill in for the removed object.
    */
    if(i<0||i>=num_entries){
        throw std::out_of_range("Invalid Index");
    }
    GameEntry e = this->entries[i];
    for(int j = i; i<num_entries-1; i++){
        this->entries[i] = this->entries[i+1];
    }
    num_entries--;
    return e;
}

int main(){
    Score sco_tue_rmVSbd_UEFC24(20);
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Real Madrid", 23));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Atletico Madrid", 21));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("FC Barcelona", 25));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Dortmund", 24));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Inter Milan", 17));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Manchester United", 9));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Manchester City", 9));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Arsenal FC", 9));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Liverpool", 14));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("PSG FC", 13));
    sco_tue_rmVSbd_UEFC24.add(GameEntry("Juventus", 11));
    GameEntry removed = sco_tue_rmVSbd_UEFC24.remove(7);
    sco_tue_rmVSbd_UEFC24.display();
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"----------|Removed Team|----------"<<std::endl;
    std::cout<<std::endl;
    removed.display();

    return 0;
}