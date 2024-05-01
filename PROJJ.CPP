#include "PROJ.h"
Danseur::Danseur(int id,string nom,string prenom,int num_tel, string email, Date date_naiss,  Categorie style,string niveau  ):personne(id,nom, prenom, num_tel, email,  date_naiss)
{
    this->style=style;
    this->niveau=niveau;
}
Danseur::Danseur(const Danseur & D)
{
    niveau=D.niveau;
    style=D.style;
}
ostream& operator<<(ostream& out, Danseur & D)
{
    out<<setw(20)<<left<<"nom"
    <<setw(20)<<left<<"prenom"
    <<setw(20)<<left<<"num_tel"
    <<setw(30)<<left<<"email"
    <<setw(20)<<left<<"id"
    <<setw(20)<<left<<"Date_naiss"
   <<setw(20)<<left<<"niveau"
    <<setw(20)<<left<<"style"<<endl
     <<setw(20)<<left<<D.nom
    <<setw(20)<<left<<D.prenom
    <<setw(20)<<left<<D.num_tel
    <<setw(30)<<left<<D.email
    <<setw(20)<<left<<D.id
    <<setw(20)<<left<<D.date_naiss.date()
    <<setw(20)<<left<<D.niveau
    <<setw(20)<<left<<D.style.getnom()<<endl;
    return out;
}
istream& operator>>(istream& in, Danseur & D)
{
    cout<<"donner le nom de danseur..."<<endl;
    in>>D.nom;
    cout<<"donner le prenom de danseur..."<<endl;
    in>>D.prenom;
    cout<<"donner le numero de telephone"<<endl;
    in>>D.num_tel;
    cout<<"donner le email ..."<<endl;
    in>>D.email;
    cout<<"donner le id ..."<<endl;
    in>>D.id;
    cout<<"donner la date de naissance de danseur..."<<endl;
    in>>D.date_naiss;
    cout<<"donner le niveau de danseur..."<<endl;
    in>>D.niveau ;
    cout<<"donner le style de danseur..."<<endl;
    in>>D.style ;
    return in;
}
Danseur::~Danseur()
{

}
void Danseur:: modifier()
{
    cout<<"menue de modification de Danseur Modifier : 1) infos generales"<<endl<<"2)niveau "<<endl<<"3)style"<<endl;
    int rep;
    cin>>rep;
    string m;
    Categorie c;
    Date d;
    switch(rep)
    {
    case 2 :
        cout <<"modification de niveau de danseur donner le niveau de cette danseur..."<<endl;
        cin>>m;
        this->niveau=m;
        break;
    case 3 :
        cout <<"modification de style de danseur ..."<<endl;
        cin>>c;
        this->style=c;
        break;
    case 1 :
    personne::modifier();
    break;
    default:
        cout<<"option introuvable"<<endl;
    }
}
void Danseur::afficher()
{
    personne::afficher();
    cout<<"le niveau de danseur est '"<<niveau<<"' affichage de categorie de cette danseur ... '"<<style<<"'"<<endl;
}
void Danseur::saisie()
{
    personne::saisie();
    cout<<"donner le niveau de danseur ..."<<endl;
    cin>>niveau;
    cout<<"donner le style de danseur..."<<endl;
    cin>>style;
}















Juge::Juge(int id,string nom , string prenom , int num_tel , string email, Date date_naiss , string specialite):personne(id,nom,prenom,num_tel,email,date_naiss)
      {
          this->specialite=specialite;
      }
Juge::~Juge()
{
//
}
void Juge::afficher()
{
    cout<<setw(20)<<left<<"nom";
    cout<<setw(20)<<left<<"prenom";
    cout<<setw(20)<<left<<"num_tel";
    cout<<setw(20)<<left<<"email";
    cout<<setw(20)<<left<<"id";
    cout<<setw(20)<<left<<"Date_naiss";
    cout<<setw(20)<<right<<"specialite"<<endl;
    cout<<setw(20)<<left<<nom;
    cout<<setw(20)<<left<<prenom;
    cout<<setw(20)<<left<<num_tel;
    cout<<setw(20)<<left<<email;
    cout<<setw(20)<<left<<id;
    cout<<setw(20)<<left<<date_naiss;
    cout<<setw(20)<<right<<specialite<<endl;
}
void Juge::saisie()
{
     personne::saisie();
     cout<<"donner la specialite de cette Juge"<<endl;
     cin>>specialite;
     cout<<"saisie de mode pass"<<endl;
}
void Juge::modifier()
{
    int rep ;
    cout<<"voulez vous modifier '1)nom ' '2)prenom' '3)num_tel' '4)email' '5)date_naissance' '6)id' '7)specialite'" "8)cancel"<<endl;
    cin>>rep;
    switch(rep)
    {
        case 1:cout<<"donner le nouveau nom de cette Juge"<<endl;cin>>nom;
        case 2:cout<<"donner le nouveau prenom de cette Juge"<<endl;cin>>prenom;
        case 3:cout<<"donner le nouveau num_tel de cette Juge"<<endl;cin>>num_tel;
        case 4:cout<<"donner le nouveau email de cette Juge"<<endl;cin>>email;
        case 5:cout<<"donner le nouveau date_nassance"<<endl;cin>>date_naiss;
        case 6:cout<<"donner le nouveau id de cette Juge"<<endl;cin>>id;
        case 7:cout<<"donner le nouveau specialite de cette Juge"<<endl;cin>>specialite;
        default:break;
    }
}
ostream& operator<<(ostream& out , Juge& j)
{
    out<<setw(20)<<left<<"nom"
    <<setw(20)<<left<<"prenom"
    <<setw(20)<<left<<"num_tel"
    <<setw(30)<<left<<"email"
    <<setw(20)<<left<<"id"
    <<setw(20)<<left<<"Date_naiss"
    <<setw(20)<<left<<"specialite"<<endl;
    out<<setw(20)<<left<<j.nom
    <<setw(20)<<left<<j.prenom
    <<setw(20)<<left<<j.num_tel
    <<setw(30)<<left<<j.email
    <<setw(20)<<left<<j.id;
    out<<setw(20)<<left<<j.date_naiss.date()
    <<setw(20)<<left<<j.specialite<<endl;
    return out;
}
istream& operator>>(istream& in , Juge& j)
{
    cout<<"donner le nom de cette Juge"<<endl;cin>>j.nom;
    cout<<"donner le prenom de cette Juge"<<endl;cin>>j.prenom;
    cout<<"donner le numero de telephone de cette Juge"<<endl;cin>>j.num_tel;
    cout<<"donner le email de cette Juge"<<endl;cin>>j.email;
    cout<<"donner la date de naissance de cette Juge"<<endl;cin>>j.date_naiss;
    cout<<"donner le id de cette Juge"<<endl;cin>>j.id;
    cout<<"donner la specialite de cette Juge"<<endl;cin>>j.specialite;
    return in;
}
Note Juge::attribue(Equipe& e)
{
    cout<<"attribution de Note de juge d'id : '"<<id<<"' a l'equipe d'id : ' "<<e.getid()<<"' "<<endl;
    Note n;
    float r;
    n.setid(e.getid());
    cout<<"donner une Note sur la technique de cette equipe (entre 0-5)"<<endl;
    cin>>r;n.sett(r);
    cout<<"donner une Note sur l'expression artistique de cette equipe (entre 0-5)"<<endl;
    cin>>r;n.sete(r);
    cout<<"donner une Note sur la synchronisation de cette equipe (entre 0-5)"<<endl;
    cin>>r;n.sets(r);
    return(n);
}
int Juge::getid()
{
    return (id);
}





Performance::Performance(int id ,vector<Juge*>list_juges,  Temps duree , Date date )
{
cout<<"debut de la construction de la performances"<<endl;
 this->id=id;
 cout<<"done!!!"<<endl;
 this->duree=duree;
 this->date=date;
 this->les_juges=list_juges;
}
Performance::Performance(const Performance& p )
{
    this->id=p.id;
    this->duree=p.duree;
    this->date=p.date;
    vector<Juge*>les_juges;
    for(int i = 0  ; i < les_juges.size() ; i++)
    {
        this->les_juges.push_back(p.les_juges[i]);
    }
    this->note=p.note;
    this->initializee=p.initializee;
}
Performance::~Performance()
{
 ////////////////////
 /////////////////////

}
void Performance::afficher()
{
    if(initializee){
            cout<<"Performance ID : '"<<id<<"'"<<endl;
       cout<<"                Note:'"<<note.total()<<"'"<<endl;
       cout<<"                     Details sur la Note : technique = '"<<note.gett()<<"' expression = '"<<note.gete()<<"' synchronisation: ' "<<note.gets()<<"'"<<endl;
       cout<<"               temps:'"<<duree<<"'"<<endl;
       cout<<"                date:'"<<date<<"'"<<endl;
       cout<<"Les  3 Juges qui ont evaluees cette performance ont les ID suivantes :'"<<les_juges[0]->getid()<<"' '"<<les_juges[1]->getid()<<"' '"<<les_juges[2]->getid()<<"' " <<endl;
    }
    else cout<<"performance n'est ete pas faite encore"<<endl;
}
istream& operator>>(istream& in , Performance& p)
{
    cout<<"donner la data"<<endl;in>>p.date;
    cout<<"donner la duree"<<endl;in>>p.duree;
    cout<<p.date<<p.duree<<endl;
    return in;
}
ostream& operator<<(ostream& out , Performance& p)
{
    if(p.initializee){
       cout<<"Performance ID : '"<<p.id<<"'"<<endl;
       cout<<"                Note:'"<<p.note.total()<<"'"<<endl;
       cout<<"                     Details sur la Note : technique = '"<<p.note.gett()<<"' expression = '"<<p.note.gete()<<"' synchronisation: ' "<<p.note.gets()<<"'"<<endl;
       cout<<"               temps:'"<<p.duree<<"'"<<endl;
       cout<<"                date:'"<<p.date<<"'"<<endl;
       cout<<"Les  3 Juges qui ont evaluees cette performance ont les ID suivantes :'"<<p.les_juges[0]->getid()<<"' '"<<p.les_juges[1]->getid()<<"' '"<<p.les_juges[2]->getid()<<"' " <<endl;
    }
    else{cout<<"cette performance n'est ete pas faite encore"<<endl;}
    return out;

}
void Performance::initializer(Equipe& e)
{
    if(!initializee){
    initializee=true;
    note.setid(e.getid());
    Note n;
    for(int i = 0 ; i < 3 ; i++)
    {
        cout<<e.getid()<<endl;
       Note nj;
       nj=les_juges[i]->attribue(e);
       n=n+nj;
       cout<<"note totale sans sustraction done ! "<<endl;
    }
    n.sett(n.gett()/3);
    n.sete(n.gete()/3);
    n.sets(n.gets()/3);
    note.sett(n.gett());note.sete(n.gete());note.sets(n.gets());
    cout<<"note attribuee a la performance !!"<<endl;
    }
    else{cout<<"la performance a ete deja initializee"<<endl;}
}
int Performance::getd()
{
    return(duree.geth());
}
float Performance::getn()
{
    return(note.total());
}
int Performance::getid()
{
    return(id);
}





PhaseE::PhaseE(int idd , vector<Equipe*> list_equipes ,vector<Juge*> les_Juges)
{
    this->id=idd;
    this->list_Equipes=list_equipes;
    this->les_juges=les_Juges;
    this->Equipe_rest={};
    this->list_rounds={};
    this->initializee=false;
}
PhaseE::~PhaseE()
{
   /*   for (int i=0;i<list_Equipes.size();i++){
           delete( list_Equipes[i]);
        }
        for (int i=0;i<les_juges.size();i++){
            delete(les_juges[i]);
        }
        for (int i=0;i<Equipe_rest.size();i++){
            delete(Equipe_rest[i]);
        }
        for (int i=0;i<list_rounds.size();i++){
            delete(list_rounds[i]);
        } */
}
vector<Equipe*> PhaseE::initializer()
{
    //lets see if this phase has been initialized before.
    if(this->initializee){cout<<"error cette phase est initializee!"<<endl;}
    else
    {
        initializee=true;
        //first lets make a copy of the list of the initial teams so we don t disturb the real one
        vector<Equipe*>copy_list_Equipes;
        Equipe*p;
        for(int i=0;i<list_Equipes.size();i++){
            p=new Equipe(*list_Equipes[i]);
        copy_list_Equipes.push_back(p);
       }
        //lets see how many teams made it to this phase .
        int n = list_Equipes.size();
        //lets check is the number of teams is greater than 3 if its not we should'nt start any round
        if(n<=3){Equipe_rest=list_Equipes; return Equipe_rest;}
        else
        {
        //now lets determine how many teams should be eleminated every round to leave only 3 teams in the end of the 5th round .
        int e = static_cast<int>(ceil(n/4.0));
        //ok now lets start the rounds
        for(int i = 0 ; i < 5 ; i++)
        {
            //lets update how many teams we have
            n=copy_list_Equipes.size();
            Round * r = new Round (this->id+i,copy_list_Equipes,les_juges);
            //we should put this round in the list of rounds relative to this phase .
            list_rounds.push_back(r);
            //initialize the round and eleminate e number of teams and update the list of teams at the same time.
            //if its the 5th round lets keep 3 teams else lets keep n-e amount of people
            if(i==4&&copy_list_Equipes.size()>3){copy_list_Equipes=r->initializer(3);}
            else if(i<4&&copy_list_Equipes.size()>3){
            copy_list_Equipes=r->initializer(n-e);
            }
            else{
                break;
            }
        }
        //now we should be left with 3 teams in the copy_list_Equipes vector we just put them in the attribute equipes rest
        return(copy_list_Equipes);

        }

    }
    return {};
}




Recompense::Recompense(int id_rec , string nom , string type , string description )
{
    this->id_rec=id_rec;
    this->description=description;
    this->type=type;
    this->nom=nom;
}
Recompense::~Recompense()
{
    //
}
void Recompense::afficher()
{
    cout<<"affichage de recompense ..."<<endl;
    cout<<"le id de recompence est '"<<id_rec<<"' le nom de recompence est '"<<nom<<"'le type de recompence est '"<<type<<"' la description de cette recompence est la suivante :<<"<<description<<">>: "<<endl;
}
void Recompense::saisie()
{
    cout<<"saisie d'une recompense..."<<endl;
    cout<<"donner le id de cette recompence..."<<endl;cin>>id_rec;
    cout<<"donner le nom de cette recompence..."<<endl;cin>>nom;
    cout<<"donner le type de cette recompence..."<<endl;cin>>type;
    cout<<"donner la description de cette recompence..."<<endl;cin>>description;
}
 void Recompense::modifier()
{
    cout<<"modification d'une recompence..."<<endl;
    int rep;
    string m;
    cout<<"voulez vous modifier '1)le id ' '2)le nom ' '3)le type' ou '4)la description'"<<endl;
    cin>>rep;
    switch(rep)
    {
        case 1 :int i ; cout<<"donner le nouveau id ..."<<endl;cin>>i;id_rec=i;break;
        case 2 :cout<<"donner le nouveau nom...."<<endl;cin>>m;nom=m;break;
        case 3 :cout<<"donner le nouveau type..."<<endl;cin>>m;type=m;break;
        case 4 :cout<<"donner une nouvelle description ..."<<endl;cin>>m;description=nom;break;
    }
}





Round::Round(int id ,vector<Equipe*>list_Equipe , vector<Juge*>les_juges)
{
    this->id=id;
    this->list_Equipes=list_Equipe;
    this->list_perf={};
    this->les_juges=les_juges;
}
Round::~Round()
{
   /*  for(int i=0 ; i<list_Equipes.size() ; i++)
    {
        delete list_Equipes[i];
    }
    for(int i=0 ; i<list_perf.size() ; i++)
    {
        delete list_perf[i];
    } */
}
vector<Performance*> alg_tri_performance(vector<Performance*> list_perf)
{
    vector<Performance*> list_perf_triee;

    while (!list_perf.empty()) {
        Performance* perfmax = list_perf[0]; // Initialize perfmax in each iteration
        for (int i = 0; i < list_perf.size(); i++) {
            if (perfmax->getn() < list_perf[i]->getn()) {
                perfmax = list_perf[i];
            }
        }

        // Remove the performance from the old list
        for (auto it = list_perf.begin(); it != list_perf.end();) {
            if (perfmax->getid() == (*it)->getid()) {
                it = list_perf.erase(it);
            } else {
                ++it;
            }
        }

        // Add the max of the list into the new sorted list
        list_perf_triee.push_back(perfmax);
    }

    return list_perf_triee;
}
vector<Equipe*> Round::initializer(int m)
{
    if(!initializee)
    {
        initializee=true;
        Date date;
        Temps duree;
        cout<<"quelle est la date de debut de cette round "<<endl;cin>>date;
        cout<<"quelle est la duree de la performance pour cette Round"<<endl;cin>>duree;
        for(int i = 0 ; i<list_Equipes.size() ; i++)
        {
            //creation de la performance de l'equipe.
            Performance* p = new Performance(list_Equipes[i]->getid(),les_juges,duree,date);
            //la performance est jugee.
            p->initializer(*list_Equipes[i]);
            //la performance est inserer a la list des performance relative a cette round cette equipe maintenant attend que touts l'autre equipe finisse ses performances
            list_perf.push_back(p);
        }
        list_perf=alg_tri_performance(list_perf);
        //now we start eleminating anyone who's rank is bigger than 10.
        for(int i = 0 ; i < list_perf.size() ; i++)
        {
            if(i>m-1)
            {
            for(int j=0 ; j<list_Equipes.size() ; j++)
             {
                if(list_perf[i]->getid()==list_Equipes[j]->getid() )
                {
                    list_Equipes.erase(list_Equipes.begin()+j);
                }
             }
            }
        }
    }
    return(list_Equipes);
}







PhaseQ::PhaseQ(int idd ,vector<Equipe*> list_equipe,vector<Juge*>les_juuges,Date datee)
{
    this->initializee=false;
    this->id=idd;
    this->list_Equipe=list_equipe;
    this->list_Equipe_qualifiee={};
    this->list_performance={};
    this->les_juges=les_juuges;
    this->date=datee;
}
PhaseQ::~PhaseQ()
{
  /*   for(int i = 0 ; i<list_Equipe.size() ; i++)
    {
        delete list_Equipe[i];
    }
    for(int i=0 ; i<list_Equipe_qualifiee.size() ; i++)
    {
        delete list_Equipe_qualifiee[i];
    }
    for(int i=0 ; i<list_performance.size() ; i++)
    {
        delete list_performance[i];
    } */
}
void PhaseQ::afficher()
{
    cout<<"affichage de resultat de la phase  1 "<<endl;
    cout<<"les equipe qui ont participee : ";
    for(int i = 0 ; i < list_Equipe.size();i++)
    {
       cout<<list_Equipe[i]->getid()<<"   ,   " ;
    }
    cout<<endl;
    cout<<"les equipe qui ont qualifiee : ";
    for(int i = 0 ; i < list_Equipe_qualifiee.size();i++)
    {
       cout<<list_Equipe_qualifiee[i]->getid()<<"   ,   " ;
    }
    cout<<endl;
}
void PhaseQ::saisie()
{
  cout<<"donner la nouvelle id de cette phase"<<endl;cin>>id;
}
ostream& operator<<(ostream& out , PhaseQ& p)
{
    out<<"affichage du resultat de la phase  d'id :"<<p.id<<endl;
    out<<"les equipe qui ont participee : ";
    for(int i = 0 ; i < p.list_Equipe.size();i++)
    {
       out<<p.list_Equipe[i]->getid()<<"   ,   " ;
    }
    out<<endl;
    out<<"les equipe qui ont qualifiee : ";
    for(int i = 0 ; i < p.list_Equipe_qualifiee.size();i++)
    {
       out<<p.list_Equipe_qualifiee[i]->getid()<<"   ,   " ;
    }
    out<<endl;
    out<<"les juges:"<<endl;
    for(int y=0;y<p.les_juges.size();y++){
        out<<*p.les_juges[y]<<endl;
    }
    return out;
}
vector<Equipe*> PhaseQ::initializer()
{
    if(!initializee){
    initializee=true;
    Temps d ;
    cout<<"donner la duree d'une performance par equipe ..."<<endl;
    cin>>d;
    for(int i = 0 ; i < list_Equipe.size() ; i++)
    {
        //the team performs its dance then the performance is evaluated by the 3 juges and its added to the list of performances relative to the qualification pahse...
        Note n;
        cout<<list_Equipe[i]->getid()<<endl;
        Performance P(list_Equipe[i]->getid(),les_juges,d,date);
        P.initializer(*list_Equipe[i]);
        list_performance.push_back(&P);
        cout<<"la performance est enregistrer dans la list des performances"<<endl;
        //now we check if this team is going to be qualified ...
        if(P.getn()>3)
        {
            list_Equipe_qualifiee.push_back(list_Equipe[i]);
        }
    }

    }
    else cout<<"la phase est deja faite"<<endl;
    return(list_Equipe_qualifiee);
}
Equipe* Tournoi:: recherche_equipe()
{
    cout<<"Algrithme de recherche d'une equipe dans un tournoi"<<endl;
    cout<<"donner le id de l'equipe a rechercher"<<endl;
    int ident;
    cin>>ident;
    for(int i = 0 ; i<list_epr.size();i++)
    {
       vector<Equipe*> list_equipe;
       list_equipe = list_epr[i]->copylist();
       for(int j=0 ; j<list_equipe.size() ; j++)
       {
         if(list_equipe[j]->getid()==ident)return(list_equipe[j]);
       }
    }
    return NULL;
}

