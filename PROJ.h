#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#pragma once
class Date
{
    int jours;
    int mois;
    int annes;

public:
    Date(int j = 0, int m = 0, int a = 0)
    {
        jours = j;
        mois = m;
        annes = a;
    }
    Date(const Date &d)
    {
        jours = d.jours;
        mois = d.mois;
        annes = d.annes;
    }
    void modifier()
    {
        cout << "saisir le nouveau jour, mois et annee" << endl;
        cin >> jours >> mois >> annes;
    }

    friend ostream &operator<<(ostream &out, Date &d)
    {
        out << d.annes << "/" << d.mois << "/" << d.jours;
        return out;
    }
    friend istream &operator>>(istream &in, Date &d)
    {
        cout << "saisir le jour, mois et annees" << endl;
        in >> d.jours;
        in >> d.mois;
        in >> d.annes;
        return in;
    }

    ~Date()
    {
        //
    }
    int getj()
    {
        return (jours);
    }
    int getm()
    {
        return (mois);
    }
    int geta()
    {
        return (annes);
    }
    string date()
    {
        string date;
        date.append(to_string(jours));
        date.append("/");
        date.append(to_string(mois));
        date.append("/");
        date.append(to_string(annes));
        return (date);
    }
};

class Recompense
{
    int id_rec;
    string description;
    string type;
    string nom;

public:
    Recompense(int id_rec = 0, string description = "", string type = "", string nom = "");
    ~Recompense();
    void afficher();
    void saisie();
    friend class organisateur_Recompense;
    friend istream &operator>>(istream &in, Recompense &r)
    {
        cout << "saisie d'une Recompense..." << endl;
        cout << "donner le id de cette recompence..." << endl;
        in >> r.id_rec;
        cout << "donner le nom de cette recompence..." << endl;
        in >> r.nom;
        cout << "donner le type de cette recompence..." << endl;
        in >> r.type;
        cout << "donner la description de cette recompence..." << endl;
        in >> r.description;
        return in;
    }
    friend ostream &operator<<(ostream &out, Recompense &r)
    {
        out << "affichage recompense" << endl;
        out << setw(20) << left << "Id"
            << setw(50) << left << "Description"
            << setw(20) << left << "Type"
            << setw(20) << left << "Nom" << endl;
        out << setw(20) << left << r.id_rec
            << setw(50) << left << r.description
            << setw(20) << left << r.type
            << setw(20) << left << r.nom << endl;
        return out;
    }
    void modifier();
};

#pragma once
class Categorie
{
    string nom;
    string description;
    int id;

public:
    Categorie(string nom = "", string d = "", int id = 0)
    {
        this->nom = nom;
        this->description = d;
        this->id = id;
    }
    Categorie(const Categorie &C)
    {
        nom = C.nom;
        description = C.description;
        id = C.id;
    }
    friend ostream &operator<<(ostream &out, Categorie &C)
    {
        out << "l'id : " << C.id << "  le nom de la Categorie est  '" << C.nom << "' la description est la suivante '" << C.description << "' " << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Categorie &C)
    {
        cout << "donner le nom de la categorie..." << endl;
        in >> C.nom;
        cout << "donner la description de cette categorie de danse ..." << endl;
        in >> C.description;
        cout << "donner le id de cette categorie..." << endl;
        in >> C.id;
        return in;
    }
    string getnom()
    {
        return (nom);
    }
};

class personne
{
protected:
    string nom;
    string prenom;
    Date date_naiss;
    int num_tel;
    string email;
    int id;

public:
    friend ostream &operator<<(ostream &, personne &);
    friend istream &operator>>(istream &, personne &);
    personne(int i = 0, string n = "", string p = "", int num = 0, string ad = "", Date d = Date())
    {
        nom = n;
        prenom = p;
        date_naiss = d;
        id = i;
        num_tel = num;
        email = ad;
    }
    virtual ~personne(){};
    virtual void afficher()
    {
        cout << "nom : " << nom << endl
             << "prenom : " << prenom << endl
             << "numero de telephone : " << num_tel << endl
             << "adresse email : " << email << endl
             << "id : " << id << endl;
    }
    void saisie()
    {
        cout << "donner le nom de cette persone" << endl;
        cin >> nom;
        cout << "donner le prenom de cette persone" << endl;
        cin >> prenom;
        cout << "donner le numtel de cette persone" << endl;
        cin >> num_tel;
        cout << "donner le email de cette persone" << endl;
        cin >> email;
        cout << "donner le id de cette persone" << endl;
        cin >> id;
        cout << "donner la date de naissance de cette persone" << endl;
        cin >> date_naiss;
    }
    void setnom()
    {
        cout << "sasir le nom" << endl;
        cin >> nom;
    }
    void setprenom()
    {
        cout << "saisir le prenom" << endl;
        cin >> prenom;
    }
    void setmail()
    {
        cout << "saisir le mail" << endl;
        cin >> email;
    }
    void setid()
    {
        cout << "sasir l'id" << endl; // il faut verifier si ce id n'existe deja
        cin >> id;
    }
    void setnumtel()
    {
        cout << "saisir le numero de telephone" << endl;
        cin >> num_tel;
    }
    void modifier()
    {
        int a;
        cout << "1: modifier nom" << endl
             << "2: modifier prenom" << endl
             << "3: modifier le numero de telephone" << endl
             << "4: modifier l'adresse email" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            this->setnom();
            break;
        }
        case 2:
        {
            this->setprenom();
            break;
        }
        case 3:
        {
            this->setnumtel();
            break;
        }
        case 4:
        {
            this->setmail();
            break;
        }
        case 5:
            this->setid();
        }
    }
};
ostream &operator<<(ostream &out, personne &p)
{
    out << setw(20) << left << "nom"
        << setw(20) << left << "prenom"
        << setw(20) << left << "num_tel"
        << setw(30) << left << "email"
        << setw(20) << left << "id"
        << setw(20) << left << "Date_naiss" << endl
        << setw(20) << left << p.nom
        << setw(20) << left << p.prenom
        << setw(20) << left << p.num_tel
        << setw(30) << left << p.email
        << setw(20) << left << p.id
        << setw(20) << left << p.date_naiss.date();
    return out;
}
istream &operator>>(istream &x, personne &p)
{
    cout << "saisir le nom" << endl;
    x >> p.nom;
    cout << "saisir le prenom" << endl;
    x >> p.prenom;
    cout << "saisir la date de naissance(jour,mois et annees)" << endl;
    cin >> p.date_naiss;
    cout << "saisir le numero de telephone" << endl;
    x >> p.num_tel;
    cout << "saisir l'adresse email" << endl;
    x >> p.email;
    cout << "saisir l'id" << endl;
    x >> p.id;
    return x;
}

class Equipe
{
protected:
    int id_eqp;
    string nom;

public:
    Equipe(int id = 0, string no = "")
    {
        id_eqp = id;
        nom = no;
    }
    virtual ~Equipe(){};
    virtual void modifier()
    {
        cout << "saisir le nouveau id et le nom" << endl;
        cin >> id_eqp >> nom;
    }
    virtual void afficher()
    {
        cout << "id : " << id_eqp << endl
             << "nom : " << nom << endl;
    }
    int getid()
    {
        return id_eqp;
    }
    virtual string getnom()
    {
        return nom;
    }
    friend class organisateur;
    friend class organisateur_Recompense;
    friend ostream &operator<<(ostream &, Equipe &);
    friend istream &operator>>(istream &, Equipe &);
    friend ostream &operator<<(ostream &x, Equipe *e)
    {
        x << "id : " << e->id_eqp << endl;
        x << "nom : " << e->nom << endl;
        return x;
    }
    friend istream &operator>>(istream &x, Equipe *e)
    {
        char ch[100];
        x.getline(ch, 90, ':');
        x >> e->id_eqp;
        x.getline(ch, 90, ':');
        getline(x, e->nom);
        return x;
    }
};
ostream &operator<<(ostream &x, Equipe &e)
{
    x << "id : " << e.id_eqp << endl
      << "nom : " << e.nom << endl;
    return x;
}
istream &operator>>(istream &x, Equipe &e)
{
    cout << "saisir l' id et le nom" << endl;
    x >> e.id_eqp >> e.nom;
    return x;
}

class Danseur : public personne
{
    string niveau;
    Categorie style;

public:
    Danseur(int ID = 0, string Nom = "", string Prenom = "", int Num_tel = 0, string Email = "", Date date_naiss = Date(), Categorie style = Categorie(), string niveau = "");
    Danseur(const Danseur &);
    friend ostream &operator<<(ostream &, Danseur &);
    friend istream &operator>>(istream &, Danseur &);
    ~Danseur();
    void modifier();
    void afficher();
    void saisie();
};

class duo : public Equipe
{
    Danseur *d1;
    Danseur *d2;

public:
    duo(Danseur a = Danseur(), Danseur b = Danseur(), int id = 0, string no = "") : Equipe(id, no)
    {
        d1 = new Danseur(a);
        d2 = new Danseur(b);
    }
    ~duo() {}
    void afficher()
    {
        Equipe::afficher();
        d1->afficher();
        d2->afficher();
    }
    void modifier()
    {
        int x;
        cout << "1 : modidfier les infos generales de l'Equipe" << endl
             << "2 : modifier les infos du Danseur* 1" << endl
             << "3 : modifier les infos du Danseur* 2" << endl;
        cin >> x;
        if (x == 1)
        {
            Equipe::modifier();
        }
        else if (x == 2)
        {
            d1->modifier();
        }
        else if (x == 3)
        {
            d2->modifier();
        }
    }
    friend ostream &operator<<(ostream &, duo &);
    friend istream &operator>>(istream &, duo &);
};
ostream &operator<<(ostream &out, duo &s)
{
    cout << "----------------- affichage duo" << endl;
    Equipe *e = &s;
    cout << *e;
    cout << "----------------- affichage danseur de l'equipe" << endl;
    cout << "danseur1" << endl;
    out << *s.d1;
    cout << "danseur2" << endl;
    out << *s.d2;
    return out;
}
istream &operator>>(istream &x, duo &s)
{
    Equipe *e = &s;
    x >> *e;
    x >> *s.d1;
    x >> *s.d2;
    return x;
}

class gagnant : public Equipe
{
    Recompense r;
    Date date_d_obtention;

public:
    gagnant(Recompense re = Recompense(), Date d = Date(), int id = 0, string no = "") : Equipe(id, no)
    {
        r = re;
        date_d_obtention = d;
    }
    ~gagnant() {}
    friend class organisateur_Recompense;
    void afficher()
    {
        Equipe::afficher();
        cout << "Recompense : " << r << endl
             << "date d'obtention : " << date_d_obtention << endl;
    };
    void modidfier()
    {
        int x;
        cout << "1 : modidfier les infos generales de l'Equipe" << endl
             << "2 : modifier les infos du Recompense et date d'obtention" << endl;
        cin >> x;
        if (x == 1)
        {
            Equipe::modifier();
        }
        else if (x == 2)
        {
            r.modifier();
            date_d_obtention.modifier();
        }
    }
    friend ostream &operator<<(ostream &, gagnant &);
    friend istream &operator>>(istream &, gagnant &);
};
ostream &operator<<(ostream &x, gagnant &s)
{
    x << "id : " << s.id_eqp << endl
      << "nom : " << s.nom << endl;
    x << "Recompense : " << s.r << endl
      << "date d'obtention :" << s.date_d_obtention << endl;
    return x;
}
istream &operator>>(istream &x, gagnant &s)
{
    cout << "saisir l' id, nombre de danseurs et nom" << endl;
    x >> s.id_eqp >> s.nom;
    cout << "saisir la Recompense et le date d'obtention" << endl;
    x >> s.r >> s.date_d_obtention;
    return x;
}

class Note
{
    int id;
    float technique;
    float expression;
    float synchro;

public:
    Note(int id = 0, float technique = 0, float expression = 0, float synchro = 0)
    {
        this->id = id;
        this->technique = technique;
        this->expression = expression;
        this->synchro = synchro;
    }
    Note(const Note &n)
    {
        this->id = n.id;
        this->technique = n.technique;
        this->expression = n.expression;
        this->synchro = n.synchro;
    }
    ~Note()
    {
        //
    }
    friend ostream &operator<<(ostream &out, Note &n)
    {
        cout << "affichage de Note de id " << n.id << endl;
        cout << setw(20) << left << "technique";
        cout << setw(1) << left << "|";
        cout << setw(20) << left << "expression";
        cout << setw(1) << left << "|";
        cout << setw(20) << right << "synchro" << endl;
        cout << setw(20) << left << n.technique;
        cout << setw(1) << left << "|";
        cout << setw(20) << left << n.expression;
        cout << setw(1) << left << "|";
        cout << setw(20) << right << n.synchro << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Note &n)
    {
        cout << "donner le id de cette note ..." << endl;
        cin >> n.id;
        cout << "donner la note sur la technique...." << endl;
        cin >> n.technique;
        cout << "donner la note sur l'expression...." << endl;
        cin >> n.expression;
        cout << "donner la note sur la synchronisation..." << endl;
        cin >> n.synchro;
        return in;
    }
    void afficher()
    {
        cout << "affichage de Note de id " << id << endl;
        cout << setw(20) << left << "technique";
        cout << setw(1) << left << "|";
        cout << setw(20) << left << "expression";
        cout << setw(1) << left << "|";
        cout << setw(20) << right << "synchro" << endl;
        cout << setw(20) << left << technique;
        cout << setw(1) << left << "|";
        cout << setw(20) << left << expression;
        cout << setw(1) << left << "|";
        cout << setw(20) << right << synchro << endl;
    }
    void saisie()
    {
        cout << "donner le id de cette note ..." << endl;
        cin >> id;
        cout << "donner la note sur la technique...." << endl;
        cin >> technique;
        cout << "donner la note sur l'expression...." << endl;
        cin >> expression;
        cout << "donner la note sur la synchronisation..." << endl;
        cin >> synchro;
    }
    void modifier()
    {
        char rep;
        cout << "voulez vous modifier '1)le id de note ' '2)note sur technique' '3)note sur expression' '4)note sur synchro'" << endl;
        cin >> rep;
        switch (rep)
        {
        case 1:
            cout << "donner la nouvelle id de cette note " << endl;
            cin >> id;
            break;
        case 2:
            cout << "donner la nouvelle note sur technique " << endl;
            cin >> technique;
            break;
        case 3:
            cout << "donner la nouvelle note sur expression" << endl;
            cin >> expression;
            break;
        case 4:
            cout << "donner la nouvelle note sur synchronisation" << endl;
            cin >> synchro;
            break;
        default:
            cout << "option invalid..." << endl;
            break;
        }
    }
    float total()
    {
        return ((technique * 2 + expression * 3 + synchro * 2) / 7);
    }
    friend Note operator+(Note &n1, Note &n2)
    {
        Note n;
        n.id = n1.id;
        n.technique = n1.technique + n2.technique;
        n.expression = n1.expression + n2.expression;
        n.synchro = n1.synchro + n2.synchro;
        return (n);
    }
    friend bool operator<(Note &n1, Note &n2)
    {
        return (n1.total() < n2.total());
    }
    friend bool operator>(Note &n1, Note &n2)
    {
        return (n1.total() > n2.total());
    }

    void sett(float t)
    {
        technique = t;
    }
    void sete(float e)
    {
        expression = e;
    }
    void sets(float s)
    {
        synchro = s;
    }
    void setid(int id)
    {
        this->id = id;
    }
    float gett()
    {
        return (technique);
    }
    float gete()
    {
        return (expression);
    }
    float gets()
    {
        return (synchro);
    }
};

#pragma once

class Juge : public personne
{
    string specialite;

public:
    Juge(int id = 0, string nom = "", string prenom = "", int num_tel = 0, string email = "", Date date_naiss = Date(), string specialite = "");
    ~Juge();
    friend class organisateur_Juge;
    friend ostream &operator<<(ostream &, Juge &);
    friend istream &operator>>(istream &, Juge &);
    friend ostream &operator<<(ostream &out, Juge *j)
    {
        out << setw(20) << left << "nom"
            << setw(20) << left << "prenom"
            << setw(20) << left << "num_tel"
            << setw(30) << left << "email"
            << setw(20) << left << "id"
            << setw(20) << left << "Date_naiss"
            << setw(20) << left << "specialite" << endl;
        out << setw(20) << left << "." + j->nom
            << setw(20) << left << j->prenom
            << setw(20) << left << j->num_tel
            << setw(30) << left << j->email
            << setw(20) << left << j->id;
        out << setw(20) << left << j->date_naiss.date()
            << setw(20) << left << j->specialite << endl;
        return out;
    }
    friend istream &operator>>(istream &x, Juge *e)
    {
        char ch[200];
        x.getline(ch, 190, '.');
        x >> e->nom;
        cout << e->nom << endl;
        x >> e->prenom;
        x >> e->num_tel;
        x >> e->email;
        x >> e->id;
        int day, month, year;
        x >> day;
        x.ignore(1, '/');
        x >> month;
        x.ignore(1, '/');
        x >> year;
        Date d(day, month, year);
        e->date_naiss = d;
        x >> e->specialite;
        return x;
    }

    void afficher();
    void saisie();
    void modifier();
    Note attribue(Equipe &);
    int getid();
};

class Temps
{
    int secondes;
    int minutes;
    int heures;

public:
    Temps(int heures = 0, int minutes = 0, int secondes = 0)
    {
        this->heures = heures;
        this->minutes = minutes;
        this->secondes = secondes;
    }
    ~Temps()
    {
        //
    }
    friend ostream &operator<<(ostream &out, Temps &t)
    {
        out << t.heures << ":" << t.minutes << ":" << t.secondes << endl;
        return out;
    }
    friend istream &operator>>(istream &in, Temps &t)
    {
        cout << "donner l'heure..." << endl;
        while (1)
        {
            cin >> t.heures;
            if (t.heures <= 24 && t.heures >= 0)
            {
                break;
            }
        }
        cout << "donner les menutes..." << endl;
        while (1)
        {
            cin >> t.minutes;
            if (t.minutes <= 60 && t.minutes >= 0)
            {
                break;
            }
        }
        cout << "donner les secondes..." << endl;
        while (1)
        {
            cin >> t.secondes;
            if (t.secondes <= 60 && t.secondes >= 0)
            {
                break;
            }
        }
        return in;
    }
    friend bool operator==(Temps &t1, Temps &t2)
    {
        return ((t1.heures == t2.heures) && (t1.minutes == t2.minutes) && (t1.secondes) && (t2.secondes));
    }
    void afficher()
    {
        cout << heures << "/" << minutes << "/" << secondes;
    }
    void sasie()
    {
        cout << "donner l'heure..." << endl;
        cin >> heures;
        cout << "donner les menutes..." << endl;
        cin >> minutes;
        cout << "donner les secondes..." << endl;
        cin >> secondes;
    }
    friend bool operator>(Temps &t1, Temps &t2)
    {
        if (t1.heures > t2.heures)
        {
            return true;
        }
        else if (t1.heures < t2.heures)
        {
            return false;
        }
        else
        {
            if (t1.minutes > t2.minutes)
            {
                return true;
            }
            else if (t1.minutes < t2.minutes)
            {
                return false;
            }
            else
            {
                if (t1.secondes > t2.secondes)
                {
                    return true;
                }
                else
                    return false;
            }
        }
    }

    friend bool operator<(Temps &t1, Temps &t2)
    {
        if (t1.heures < t2.heures)
        {
            return true;
        }
        else if (t1.heures > t2.heures)
        {
            return false;
        }
        else
        {
            if (t1.minutes < t2.minutes)
            {
                return true;
            }
            else if (t1.minutes > t2.minutes)
            {
                return false;
            }
            else
            {
                if (t1.secondes < t2.secondes)
                {
                    return true;
                }
                else
                    return false;
            }
        }
    }
    friend Temps operator+(Temps &t1, Temps &t2)
    {
        Temps t;
        t.heures = t1.heures + t2.heures;
        t.minutes = t1.minutes + t2.minutes;
        t.secondes = t1.secondes + t2.secondes;
        return (t);
    }
    int geth()
    {
        return (heures);
    }
    int getm()
    {
        return (minutes);
    }
    int gets()
    {
        return (secondes);
    }
};

#pragma once

class Performance
{
    int id;
    Note note;
    Temps duree;
    Date date;
    vector<Juge *> les_juges;
    bool initializee = false;

public:
    Performance(int id = 0, vector<Juge *> les_juges = {}, Temps duree = Temps(), Date date = Date());
    Performance(const Performance &);
    ~Performance();
    void afficher();
    void saisie();
    void modifier();
    Performance &operator=(const Performance &p)
    {
        this->id = p.id;
        this->note = p.note;
        this->duree = p.duree;
        for (int i = 0; i < p.les_juges.size(); i++)
        {
            this->les_juges.push_back(p.les_juges[i]);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, Performance &p);
    friend istream &operator>>(istream &in, Performance &p);
    void initializer(Equipe &);
    int getd();
    float getn();
    int getid();
};

class Round
{
    int id;
    vector<Equipe *> list_Equipes;
    vector<Performance *> list_perf;
    vector<Juge *> les_juges;
    bool initializee = false;

public:
    Round(int id = 0, vector<Equipe *> list_Equipes = {}, vector<Juge *> les_juges = {});
    ~Round();
    // void afficher();
    // void saisie();
    friend ostream &operator<<(ostream &x, Round &r)
    {
        x << "id : " << r.id << endl;
        x << "liste des equipes : " << endl;
        for (int i = 0; i < r.list_Equipes.size(); i++)
        { ////tets here yoooooooooooow
            x << *r.list_Equipes[i] << endl;
        }
        x << "liste des performances :" << endl;
        for (int i = 0; i < r.list_perf.size(); i++)
        {
            x << *r.list_perf[i] << endl;
        }
        x << "liste des juges : " << endl;
        for (int i = 0; i < r.les_juges.size(); i++)
        {
            x << *r.les_juges[i] << endl;
        }
        return x;
    };
    friend istream &operator>>(istream &x, Round &r)
    {
        cout << "saisir l'id" << endl;
        x >> r.id;
        int u;
        cout << "saisir le nombre des equipes a enregistrer" << endl;
        x >> u;
        for (int i = 0; i < u; i++)
        {
            Equipe *e;
            x >> *e;
            r.list_Equipes.push_back(e);
        }
        cout << "nombre des performances :" << endl;
        x >> u;
        for (int i = 0; i < u; i++)
        {
            Performance *p;
            x >> *p;
            r.list_perf.push_back(p);
        }
        cout << "nombre des juges : " << endl;
        x >> u;
        for (int i = 0; i < u; i++)
        {
            Juge *j;
            x >> *j;
            r.les_juges.push_back(j);
        }
        return x;
    };
    vector<Equipe *> initializer(int);
};

class PhaseE
{
    int id;
    vector<Equipe *> list_Equipes;
    vector<Juge *> les_juges;
    vector<Equipe *> Equipe_rest;
    vector<Round *> list_rounds;
    bool initializee;

public:
    PhaseE(int idd = 0, vector<Equipe *> list_equipes = {}, vector<Juge *> les_Juges = {});
    ~PhaseE();
    bool initialized()
    {
        return (initializee);
    }
    vector<Equipe *> initializer();
    PhaseE &operator=(const PhaseE &p)
    {
        this->id = p.id;
        for (int i = 0; i < p.list_Equipes.size(); i++)
        {
            this->list_Equipes.push_back(p.list_Equipes[i]);
        }
        for (int i = 0; i < p.les_juges.size(); i++)
        {
            this->les_juges.push_back(p.les_juges[i]);
        }
        for (int i = 0; i < p.Equipe_rest.size(); i++)
        {
            this->Equipe_rest.push_back(p.Equipe_rest[i]);
        }
        for (int i = 0; i < p.list_rounds.size(); i++)
        {
            this->list_rounds.push_back(p.list_rounds[i]);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &x, PhaseE &p)
    {
        x << "id de la phase:" << endl
          << p.id << endl;
        x << "Les Equipes qui ont aboutis a cette phase:" << endl;
        for (int i = 0; i < p.list_Equipes.size(); i++)
        {
            x << *p.list_Equipes[i] << endl;
        }
        x << "Les Juges de cette Phase:" << endl;
        for (int i = 0; i < p.les_juges.size(); i++)
        {
            x << *p.les_juges[i] << endl;
        }
        x << "Les Equipes Restantes (gagnants) de cette phase:" << endl;
        for (int i = 0; i < p.Equipe_rest.size(); i++)
        {
            x << *p.Equipe_rest[i] << endl;
        }
        x << "Les rounds qui ont ete deroulees:" << endl;
        if (p.list_rounds.size() > 0)
        {
            for (int i = 0; i < p.list_rounds.size(); i++)
            {
                x << *p.list_rounds[i] << endl;
            }
        }
        else
            x << "Aucun round a ete lancee" << endl;
        return x;
    }
    friend istream &operator>>(istream &x, PhaseE &p)
    {
        cout << "id :" << endl;
        x >> p.id;
        int q;
        cout << "saisir le nombre des equipe" << endl;
        for (int i = 0; i < p.list_Equipes.size(); i++)
        {
            Equipe *e;
            x >> *e;
            p.list_Equipes.push_back(e);
        }
        for (int i = 0; i < p.les_juges.size(); i++)
        {
            Juge *j;
            x >> *j;
            p.les_juges.push_back(j);
        }
        for (int i = 0; i < p.Equipe_rest.size(); i++)
        {
            Equipe *e;
            x >> *e;
            p.Equipe_rest.push_back(e);
        }
        for (int i = 0; i < p.list_rounds.size(); i++)
        {
            Round *r;
            x >> *r;
            p.list_rounds.push_back(r);
        }
        return x;
    }
};

class PhaseQ
{
    bool initializee;
    int id;
    vector<Juge *> les_juges;
    vector<Equipe *> list_Equipe;
    vector<Equipe *> list_Equipe_qualifiee;
    vector<Performance *> list_performance;
    Date date;

public:
    PhaseQ(int idd = 0, vector<Equipe *> list_equipe = {}, vector<Juge *> les_juuges = {}, Date datee = Date());
    ~PhaseQ();
    bool initialized()
    {
        return (initializee);
    }
    void afficher();
    // void afficher(int id);
    void saisie();
    friend ostream &operator<<(ostream &, PhaseQ &);
    friend istream &operator>>(istream &x, PhaseQ &p)
    {
        cout << "saisir l'id" << endl; /////////////////his missing somethings yoooooooooooooooooooooooooooow
        x >> p.id;                     //////////////////////////////////////////////////////////////////////////////////////
        return x;                      /////////////////////////////////////////////////////////////////////////////////////
    };
    // void modifier();
    vector<Equipe *> initializer();
};

class solo : public Equipe
{
    Danseur *d;

public:
    solo(Danseur s = Danseur(), int id = 0, string no = "") : Equipe(id, no)
    {
        d = new Danseur(s);
    }
    ~solo()
    {
        delete d;
    }
    void afficher()
    {
        Equipe::afficher();
        d->afficher();
    }
    void modidfier()
    {
        int x;
        cout << "1 : modidfier les infos generales de l'Equipe" << endl
             << "2 : modifier les infos du Danseur" << endl;
        cin >> x;
        if (x == 1)
        {
            Equipe::modifier();
        }
        else if (x == 2)
        {
            d->modifier();
        }
    }
    solo &operator=(const solo &s)
    {
        Equipe::operator=(s);
        *this->d = *s.d;
        return *this;
    }
    friend ostream &operator<<(ostream &, solo &);
    friend istream &operator>>(istream &, solo &);
};
ostream &operator<<(ostream &out, solo &s)
{
    cout << "------------------affichage de solo" << endl;
    Equipe *e = &s;
    cout << *e;
    cout << "----------------- affichage danseurs de l'equipe" << endl;
    cout << "danseur1" << endl;
    out << *s.d;
    return out;
}
istream &operator>>(istream &x, solo &s)
{
    Equipe *e = &s;
    x >> *e;
    x >> *s.d;
    return x;
}

class squad : public Equipe
{
    vector<Danseur *> list_Danseur;

public:
    squad(Danseur d1 = Danseur(), Danseur d2 = Danseur(), Danseur d3 = Danseur(), Danseur d4 = Danseur(), int id = 0, string no = "") : Equipe(id, no)
    {
        Danseur *q = new Danseur(d1);
        list_Danseur.push_back(q);
        Danseur *v = new Danseur(d2);
        list_Danseur.push_back(v);
        Danseur *x = new Danseur(d3);
        list_Danseur.push_back(x);
        Danseur *z = new Danseur(d4);
        list_Danseur.push_back(z);
    }
    ~squad()
    {
        /* for(int i=0;i<list_Danseur.size();i++){
            delete(list_Danseur[i]);
        } */
    }
    void afficher()
    {
        Equipe::afficher();
        for (int i = 0; i < 4; i++)
        {
            list_Danseur[i]->afficher();
        }
    }
    void modifier()
    {
        int x;
        cout << "1 : modidfier les infos generales de l'Equipe" << endl
             << "2 : modifier les infos du Danseur 1" << endl
             << "3 : modifier les infos du Danseur 2" << endl
             << "4 : modifier les infos du Danseur 3" << endl
             << "5 : modifier les infos du Danseur 4" << endl;
        cin >> x;
        if (x == 1)
        {
            Equipe::modifier();
        }
        else if (x == 2)
        {
            list_Danseur[0]->modifier();
        }
        else if (x == 3)
        {
            list_Danseur[1]->modifier();
        }
        else if (x == 4)
        {
            list_Danseur[2]->modifier();
        }
        else if (x == 5)
        {
            list_Danseur[3]->modifier();
        }
    }
    squad &operator=(const squad &q)
    {
        Equipe::operator=(q);
        for (int i = 0; i < q.list_Danseur.size(); i++)
        {
            this->list_Danseur.push_back(q.list_Danseur[i]);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &, squad &);
    friend istream &operator>>(istream &, squad &);
};
ostream &operator<<(ostream &out, squad &s)
{
    out << "----------------- affichage squad " << endl;
    Equipe *e = &s;
    out << *e;
    out << "----------------- affichage danseur de l'equipe" << endl;
    out << "danseur1" << endl;
    out << *s.list_Danseur[0];
    out << "danseur2" << endl;
    out << *s.list_Danseur[1];
    out << "danseur3" << endl;
    out << *s.list_Danseur[2];
    out << "danseur4" << endl;
    out << *s.list_Danseur[3];
    return out;
}
istream &operator>>(istream &x, squad &s)
{
    Equipe *e = &s;
    x >> *e;
    if (s.list_Danseur.size() == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            Danseur d;
            x >> d;
            Danseur *a = new Danseur(d);
            s.list_Danseur.push_back(a);
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            x >> *s.list_Danseur[i];
        }
    }
    return x;
}

class Epreuve
{
    int id;
    string nom;
    int nb_Equipe;
    vector<Equipe *> list_Equipe;
    vector<Juge *> les_juges;
    Categorie categorie;
    // ena hna ma3andich el class gangant hani 5alitlik nty ba3id modifie w raka7 jawik
    vector<Equipe *> les_restant;
    vector<gagnant *> les_gagnant;
    vector<Recompense *> les_recomp;
    PhaseE phase_elim;
    PhaseQ phase_qual;
    bool initializee = false;

public:
    Epreuve(int Id = 0, string Nom = "", vector<Equipe *> list_equipe = {}, vector<Juge *> les_jugess = {}, Categorie categoriee = Categorie(), vector<Recompense *> les_recompp = {})
    {
        this->id = Id;
        this->nom = Nom;
        this->nb_Equipe = 0;

        // Assigning list_equipe
        for (int i = 0; i < list_equipe.size(); i++)
        {
            this->list_Equipe.push_back(list_equipe[i]);
        }

        // Assigning les_juges
        for (int j = 0; j < les_jugess.size(); j++)
        {
            this->les_juges.push_back(les_jugess[j]);
        }

        this->categorie = categoriee;

        // Assigning les_recomp
        for (int k = 0; k < les_recompp.size(); k++)
        {
            this->les_recomp.push_back(les_recompp[k]);
        }

        this->les_restant = {};
    }
    void creerfEqp(fstream &f)
    {
        f.open("C:\\Users\\PC\\Desktop\\Tournoi\\Equipes de l'epreuve " + nom + ".txt", ios::in | ios::out | ios::trunc);
        if (!f.is_open())
            exit(-1);
    }
    void LirefEqp(fstream &f)
    {
        f.open("C:\\Users\\PC\\Desktop\\Tournoi\\Equipes de l'epreuve " + nom + ".txt", ios::in);
        if (!f.is_open())
            exit(-2);
    }
    void creefju(fstream &f)
    {
        f.open("C:\\Users\\PC\\Desktop\\Tournoi\\Juges de l'epreuve " + nom + ".txt", ios::in | ios::out | ios::trunc);
        if (!f.is_open())
            exit(-3);
    }
    void Lirefju(fstream &f)
    {
        f.open("C:\\Users\\PC\\Desktop\\Tournoi\\Juges de l'epreuve " + nom + ".txt", ios::in);
        if (!f.is_open())
            exit(-4);
    }
    vector<Equipe *> geteqp()
    {
        return list_Equipe;
    }
    vector<Juge *> getju()
    {
        return les_juges;
    }

    ~Epreuve(){
        /* for(int i=0;i<list_Equipe.size();i++){
            delete list_Equipe[i];
        }
        for(int j=0;j<les_juges.size();j++){
            delete les_juges[j];
        }
        for(int k=0;k<les_recomp.size();k++){
            delete les_recomp[k];
        } */
    };
    void initializer()
    {
        if (initializee)
            cout << "epreuve deja initialisee" << endl;
        else
        {
            if (les_juges.size() == 3 && list_Equipe.size() >= 3 && les_recomp.size() == 3)
            {
                /*   vector<Equipe*> copy;
              Equipe*p;
              for(int i=0;i<list_Equipe.size();i++){
                      p=new Equipe(*list_Equipe[i]);
               copy.push_back(p);
              } */
                initializee = true;
                // creation de la phase de qualification .we need the date of the initialization in real time
                cout << "donner la date de debut de la phase de qualification" << endl;
                Date d;
                cin >> d;
                phase_qual = PhaseQ(this->id, list_Equipe, les_juges, d);
                vector<Equipe *> list_equipe_qualifiee = phase_qual.initializer();
                // creation de la phase de elimination .
                phase_elim = PhaseE(this->id, list_equipe_qualifiee, les_juges);
                // initializer la phase d'eliminaiton
                les_restant = phase_elim.initializer(); ///////////////////////////////////////////////////////////////////////////////////////////////
            }
            else
                cout << "cette epreuve ne peut pas demarrer car il ya manque des equipes, juges ou recompenses associees" << endl;
        }
    };
    friend class organisateur;
    friend class organisateur_Recompense;
    friend ostream &operator<<(ostream &, Epreuve &);
    friend istream &operator>>(istream &, Epreuve &);
    friend class organisateur_Juge;
    int getid()
    {
        return id;
    }
    void afficher(){};
    void modifier(){};
    vector<Equipe *> copylist()
    {
        vector<Equipe *> copy;
        for (int i = 0; i < list_Equipe.size(); i++)
        {
            Equipe *p;
            if (typeid(*list_Equipe[i]) == typeid(solo))
            {
                p = new solo(static_cast<const solo &>(*list_Equipe[i]));
            }
            else if (typeid(*list_Equipe[i]) == typeid(duo))
            {
                p = new duo(static_cast<const duo &>(*list_Equipe[i]));
            }
            else
            {
                p = new squad(static_cast<const squad &>(*list_Equipe[i]));
            }
            copy.push_back(p);
        }
        return (copy);
    }
};
ostream &operator<<(ostream &x, Epreuve &e)
{
    x << "affichage d'Une Epreuve : " << endl;
    x << "id : " << e.id << endl
      << "nom : " << e.nom << endl
      << "nombre des equipes : " << e.list_Equipe.size() << endl
      << "categorie : " << e.categorie << endl;
    x << "les equipes :" << endl;
    for (int i = 0; i < e.list_Equipe.size(); i++)
    {
        if (typeid(*e.list_Equipe[i]) == typeid(solo))
        {
            x << static_cast<solo &>(*(e.list_Equipe[i])) << endl;
        }
        else if (typeid(*e.list_Equipe[i]) == typeid(duo))
        {
            x << static_cast<duo &>(*(e.list_Equipe[i])) << endl;
        }
        else if (typeid(*e.list_Equipe[i]) == (typeid(squad)))
        {
            x << static_cast<squad &>(*(e.list_Equipe[i])) << endl;
        }
        else
        {
            x << *e.list_Equipe[i] << endl;
        }
    }
    x << "les juges :" << endl;
    for (int j = 0; j < e.les_juges.size(); j++)
    {
        x << *(e.les_juges[j]) << endl;
    }
    x << "les Recompenses : " << endl;
    for (int k = 0; k < e.les_recomp.size(); k++)
    {
        x << *(e.les_recomp[k]) << endl;
    }
    x << "phase de qualification : " << endl;
    if (e.phase_qual.initialized())
    {
        x << e.phase_qual << endl;
    }
    else
        cout << "pas encore initialisee....." << endl;
    x << "phase d'elimination :" << endl;
    if (e.phase_elim.initialized())
    {
        x << e.phase_elim << endl;
    }
    else
        cout << "pas encore initialisee..." << endl;
    x << "les restants (pas encore affectee une recompense):" << endl;
    if (e.les_restant.size() > 0)
    {
        for (int l = 0; l < e.les_restant.size(); l++)
        {
            x << *(e.les_restant[l]) << endl;
        }
    }
    else
        x << "pas encore d'equipe restantes..." << endl;
    x << "les gagnants (affectee une recompense):" << endl;
    if (e.les_gagnant.size() > 0)
    {
        for (int l = 0; l < e.les_gagnant.size(); l++)
        {
            x << *(e.les_gagnant[l]) << endl;
        }
    }
    else
        x << "pas encore de gagants..." << endl;
    return x;
}

istream &operator>>(istream &x, Epreuve &e)
{
    cout << "saisir l'id" << endl;
    x >> e.id;
    cout << "saisir le nom de l'epreuve" << endl;
    x >> e.nom;
    cout << "saisir le nombre des equipes" << endl;
    x >> e.nb_Equipe;
    cout << "saisir la categorie" << endl;
    x >> e.categorie;
    for (int i = 0; i < e.nb_Equipe; i++)
    {
        Equipe *p;
        int y;
        cout << "choisir le type de l'equipe No " << i + 1 << endl;
        cout << "1 : Solo" << endl
             << "2 : Duo" << endl
             << "3 : Squad" << endl;
        x >> y;
        if (y == 1)
        {
            p = new solo;
            x >> static_cast<solo &>(*p);
            e.list_Equipe.push_back(p);
        }
        else if (y == 2)
        {
            p = new duo;
            x >> static_cast<duo &>(*p);
            e.list_Equipe.push_back(p);
        }
        else if (y == 3)
        {
            p = new squad;
            x >> static_cast<squad &>(*p);
            e.list_Equipe.push_back(p);
        }
    }
    cout << "saisie les 3 juges" << endl;
    for (int k = 0; k < 3; k++)
    {
        Juge a;
        x >> a;
        Juge *q = new Juge(a);
        e.les_juges.push_back(q);
    }
    cout << "saisir les 3 recompances" << endl;
    for (int k = 0; k < 3; k++)
    {
        Recompense b;
        x >> b;
        Recompense *q = new Recompense(b);
        e.les_recomp.push_back(q);
    }
    return x;
}

class Tournoi
{
    string titre;
    int id_tour;
    int nb_epr;
    Date date_debut;
    Date date_fin;
    vector<Epreuve *> list_epr;

public:
    Tournoi(string titre = "", int id_tour = 0, Date date_debut = Date(), Date date_fin = Date())
    {
        this->titre = titre;
        this->id_tour = id_tour;
        this->date_debut = date_debut;
        this->date_fin = date_fin;
    };
    Equipe *recherche_equipe();
    void AjouterEpr(Epreuve *e)
    {
        list_epr.push_back(e);
    }
    void initEpr()
    {
        cout << "saisir l'id de";
    }
    Epreuve &getepr(int q)
    {
        for (int i = 0; i < list_epr.size(); i++)
        {
            if (list_epr[i]->getid() == q)
            {
                return *list_epr[i];
            }
        }
        return *list_epr[0];
    }
    ~Tournoi()
    {
        for (int i = 0; i < list_epr.size(); i++)
        {
            delete (list_epr[i]);
        }
    };
    friend class organisateur_Epreuve;
    friend class organisateur_Juge;
    friend class organisateur;
    friend class organisateur_Recompense;
    friend ostream &operator<<(ostream &x, Tournoi &t)
    {
        x << "titre : " << t.titre << endl
          << "id : " << t.id_tour << endl
          << "date de debut : " << t.date_debut << endl
          << "date fin : " << t.date_fin << endl
          << "nombre des epreuves : " << t.list_epr.size() << endl;
        for (int i = 0; i < t.list_epr.size(); i++)
        {
            x << *t.list_epr[i] << endl;
        }
        return x;
    };
    friend istream &operator>>(istream &x, Tournoi &t)
    {
        cout << "saisir titre :" << endl;
        x >> t.titre;
        cout << "saisir l'id : " << endl;
        x >> t.id_tour;
        cout << "saisir la date de debut : " << endl;
        x >> t.date_debut;
        cout << "saisir la date fin : " << endl;
        x >> t.date_fin;
        cout << "saisir le nombre des epreuves : " << endl;
        x >> t.nb_epr;
        for (int i = 0; i < t.nb_epr; i++)
        {
            Epreuve e;
            x >> e;
            Epreuve *q = new Epreuve(e);
            t.list_epr.push_back(q);
        }
        return x;
    };
    friend class organisateur_Epreuve;
    void saisie()
    {
        cout << "saisir titre :" << endl;
        cin >> titre;
        cout << "saisir l'id : " << endl;
        cin >> id_tour;
        cout << "saisir la date de debut : " << endl;
        cin >> date_debut;
        cout << "saisir la date fin : " << endl;
        cin >> date_fin;
        for (int i = 0; i < list_epr.size(); i++)
        {
            Epreuve *e;
            cin >> *e;
            list_epr.push_back(e);
        }
    };
    void afficher()
    {
        cout << "titre : " << titre << endl
             << "id : " << id_tour << endl
             << "date de debut : " << date_debut << endl
             << "date fin : " << date_fin << endl
             << "nombre des epreuves : " << list_epr.size() << endl;
        for (int i = 0; i < list_epr.size(); i++)
        {
            cout << *list_epr[i] << endl;
        }
    };
    void modifier()
    {
        int a;
        cout << "1 : modifier titre" << endl
             << "2 : modifier date debut" << endl
             << "3 : modifier date fin" << endl
             << "4 : modofier une epreuve" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "saisir le nouveau titre" << endl;
            cin >> titre;
            break;
        }
        case 2:
        {
            date_debut.modifier();
            break;
        }
        case 3:
        {
            date_fin.modifier();
            break;
        }
        case 4:
        {
            int e;
            cout << "saisir l'id de l'epreuve" << endl;
            cin >> e;
            for (int i = 0; i < list_epr.size(); i++)
            {
                if (list_epr[i]->getid() == e)
                {
                    list_epr[i]->modifier();
                }
            }
        }
        }
    };
};

class organisateur : public personne
{
protected:
    list<Equipe *> Equipe_enregistrees;
    string mdp;
    bool auth;

public:
    organisateur(string n = "", string p = "", int i = 0, int num = 0, string ad = "", Date d = Date()) : personne(i, n, p, num, ad, d)
    {
        mdp = "0000";
        auth = false;
    }
    ~organisateur()
    {
        list<Equipe *>::iterator it;
        for (auto it = Equipe_enregistrees.begin(); it != Equipe_enregistrees.end(); it++)
        {
            delete *it;
        }
        Equipe_enregistrees.clear();
    }
    int getid()
    {
        return id;
    }
    organisateur(const organisateur &o) : personne(o)
    {
        mdp = o.mdp;
        auth = o.auth;
        for (auto it = o.Equipe_enregistrees.begin(); it != o.Equipe_enregistrees.end(); it++)
        {
            Equipe_enregistrees.push_back(*it);
        }
    }
    virtual void enregistrerEqp(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {

                cout << "saisir l'id de l'epreuve" << endl;
                int idep;
                cin >> idep;
                int i;
                for (int i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->getid() == idep)
                    {
                        if (t->list_epr[i]->initializee == false)
                        {
                            cout << "choisir le type de l'equipe :" << endl
                                 << "1 : Solo" << endl
                                 << "2 : Duo" << endl
                                 << "3 : Squad" << endl;
                            int m;
                            cin >> m;
                            Equipe *q;
                            Equipe *v;
                            if (m == 1)
                            {
                                v = new solo;
                                q = new solo;
                                cin >> static_cast<solo &>(*q);
                                *v = *q;
                            }
                            else if (m == 2)
                            {
                                v = new duo;
                                q = new duo;
                                cin >> static_cast<duo &>(*q);
                                *v = *q;
                            }
                            else if (m == 3)
                            {
                                v = new squad;
                                q = new squad;
                                cin >> static_cast<squad &>(*q);
                                *v = *q;
                            }
                            Equipe_enregistrees.push_back(q);
                            t->list_epr[i]->list_Equipe.push_back(v);
                        }
                        else
                            cout << "ERREUR, Epreuve deja intialisee" << endl;
                        break;
                    }
                }
                if (i == t->list_epr.size())
                    cout << "epreuve inexistant" << endl;
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    virtual void afficher()
    {
        personne::afficher();
        cout << "les Equipes enregistrees par vous : " << endl;
        for (auto it = Equipe_enregistrees.begin(); it != Equipe_enregistrees.end(); it++)
        {
            (*it)->afficher();
            cout<<"--------------------------------------"<<endl;
        }
    }
    virtual bool s_authentifier()
    {
        int i = 3;
        while (i > 0 && auth == false)
        {
            string a;
            cout << "saisir votre mot de passe (vous avez " << i << " tentatives restantes)" << endl;
            cin >> a;
            if (a == mdp)
            {
                auth = true;
                return true;
            }
            cout << "mot de passe incorrect !!" << endl;
            i -= 1;
        }
        cout << "vous avez depasser la limite des tentatives d'authentification, merci de consulter l'Admin" << endl;
        return false;
    }
    virtual void SeDeconnecter()
    {
        auth = false;
    }
    virtual void modifier(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                int c;
                cout << "1 : modifier les infos personnelles" << endl
                     << "2 : modifier les infos relatives a une equipe deja enregistree" << endl;
                cin >> c;
                if (c == 1)
                {
                    int a;
                    cout << "1: modifier les infos autres que la mot de passe" << endl
                         << "2: changer le mot de passe" << endl;
                    cin >> a;
                    if (a == 1)
                        personne::modifier();
                    else if (a == 2)
                    {
                        if (this->s_authentifier() == true)
                        {
                            cout << "saisir le nouveau mot de passe" << endl;
                            cin >> mdp;
                        }
                    }
                }
                else
                {
                    int x;
                    cout << "saisir l'id de l'equipe" << endl;
                    cin >> x;
                    int s;
                    cout << "saisir l'id de l'epreuve" << endl;
                    cin >> s;
                    for (int i = 0; i < t->list_epr.size(); i++)
                    {
                        if (t->list_epr[i]->id == s)
                        {
                            for (int j = 0; j < t->list_epr[i]->list_Equipe.size(); j++)
                            {
                                if (t->list_epr[i]->list_Equipe[j]->getid() == x)
                                {
                                    t->list_epr[i]->list_Equipe[j]->modifier();
                                }
                            }
                        }
                    }
                }
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    organisateur &operator=(const organisateur &o)
    {
        if (this != &o)
        {
            for (auto it = Equipe_enregistrees.begin(); it != Equipe_enregistrees.end(); it++)
            {
                delete *it;
            }
            Equipe_enregistrees.clear();
            personne::operator=(o);
            mdp = o.mdp;
            auth = o.auth;
            for (auto it = o.Equipe_enregistrees.begin(); it != o.Equipe_enregistrees.end(); it++)
            {
                Equipe_enregistrees.push_back(*it);
            }
        }
        return *this;
    };
    friend ostream &operator<<(ostream &, organisateur &);
    friend istream &operator>>(istream &, organisateur &);
};
ostream &operator<<(ostream &x, organisateur &o)
{
    personne *q = &o;
    x << *q << endl;
    x << "Mot de passe : " << o.mdp << endl
      << "Authentification status : " << o.auth << endl;
    x << "Les equipes enregistrees par vous" << endl;
    for (auto it = o.Equipe_enregistrees.begin(); it != o.Equipe_enregistrees.end(); it++)
    {
        x << **it << endl;
    }
    return x;
}
istream &operator>>(istream &x, organisateur &o)
{
    personne *q = &o;
    x >> *q;
    cout << "saisir une mot de passe" << endl;
    x >> o.mdp;
    return x;
}

class organisateur_Epreuve : public organisateur
{
    list<Epreuve *> list_eprv;

public:
    organisateur_Epreuve(int nb = 2, string n = "", string p = "", int i = 0, int num = 0, string ad = "") : organisateur(n, p, i, num, ad)
    {
    }
    organisateur_Epreuve(const organisateur_Epreuve &o) : organisateur(o.nom, o.prenom, o.id, o.num_tel, o.email, o.date_naiss)
    {
        for (auto it = o.list_eprv.begin(); it != o.list_eprv.end(); it++)
        {
            list_eprv.push_back(*it);
        }
    }
    ~organisateur_Epreuve()
    {
        for (auto it = list_eprv.begin(); it != list_eprv.end(); it++)
        {
            delete (*it);
        }
        list_eprv.clear();
    }
    void afficher()
    {
        organisateur::afficher();
        cout << "liste des Epreuves enregistrees par vous : " << endl;
        for (auto it = list_eprv.begin(); it != list_eprv.end(); it++)
        {
            (*it)->afficher();
        }
    }
    void consulter(Epreuve *e)
    {
        cout << *e;
    }
    void creerEpreuve(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                Epreuve e;
                cin >> e;
                Epreuve *q = new Epreuve(e);
                t->list_epr.push_back(q);
                Epreuve *v = new Epreuve(e);
                list_eprv.push_back(v);
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    void modifier(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                cout << "saisir l'id de l'epreuve que vous voulez modifier" << endl;
                int id_ep;
                cin >> id_ep;
                for (int i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->getid() == id_ep)
                    {
                        t->list_epr[i]->modifier();
                        break;
                    }
                }
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    void annuler(Tournoi *t, int id_ep)
    {
        while (1)
        {
            if (this->auth == true)
            {
                cout << "saisir l'id de l'epreuve que vous voulez annuler" << endl;
                int id_ep;
                cin >> id_ep;
                for (int i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->getid() == id_ep)
                    {
                        delete (t->list_epr[i]);
                        t->list_epr.erase(t->list_epr.begin() + i);
                        break;
                    }
                }
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    organisateur_Epreuve &operator=(const organisateur_Epreuve &o)
    {
        if (this != &o)
        {
            for (auto it = list_eprv.begin(); it != list_eprv.end(); ++it)
            {
                delete (*it);
            }
            list_eprv.clear();
            organisateur::operator=(o);
            for (auto it = o.list_eprv.begin(); it != o.list_eprv.end(); it++)
            {
                list_eprv.push_back(*it);
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &, organisateur_Epreuve &);
    friend istream &operator>>(istream &, organisateur_Epreuve &);
};
ostream &operator<<(ostream &x, organisateur_Epreuve &o)
{
    organisateur *q = &o;
    x << *q;
    x << "liste des Epreuves enregistree : " << endl;
    for (auto it = o.list_eprv.begin(); it != o.list_eprv.end(); it++)
    {
        x << **it << endl;
    }
    return x;
}
istream &operator>>(istream &x, organisateur_Epreuve &o)
{
    organisateur *q = &o;
    x >> *q;
    return x;
}

class organisateur_Juge : public organisateur
{
    map<int, vector<Juge *>> list_Juges;

public:
    organisateur_Juge(string nn = "", string p = "", int i = 0, int num = 0, string ad = "") : organisateur(nn, p, i, num, ad)
    {
    }
    ~organisateur_Juge()
    {
        for (auto &pair : list_Juges)
        {
            for (int i = 0; i < pair.second.size(); i++)
            {
                delete (pair.second[i]);
            }
            pair.second.clear();
        }
    }
    void Afficher_list_Juge(Tournoi *t)
    {
        cout << "saisir l'id de l'epreuve que vous voulez afficher ses juges" << endl;
        int idep;
        cin >> idep;
        int i;
        for (i = 0; i < t->list_epr.size(); i++)
        {
            if (t->list_epr[i]->id == idep)
            {
                for (int j = 0; j < t->list_epr[i]->les_juges.size(); j++)
                {
                    cout << *t->list_epr[i]->les_juges[j] << endl
                         << endl;
                }
                break;
            }
        }
        if (i == t->list_epr.size())
            cout << "Erreur,epreuve inexistant" << endl;
    }
    void Assigner(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                cout << "saisir l'id de l'epreuve" << endl;
                int idep;
                cin >> idep;
                int i;
                for (i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->id == idep)
                    {
                        if (t->list_epr[i]->les_juges.size() < 3)
                        {
                            Juge j;
                            cin >> j;
                            Juge *q = new Juge(j);
                            t->list_epr[i]->les_juges.push_back(q);
                            Juge *v = new Juge(j);
                            if (list_Juges.count(t->list_epr[i]->getid()) > 0)
                            {
                                list_Juges[t->list_epr[i]->getid()].push_back(v);
                            }
                            else
                            {
                                pair<int, vector<Juge *>> p(t->list_epr[i]->getid(), {v});
                                list_Juges.insert(p);
                            }
                        }
                        else
                        {
                            cout << "vous ne pouvez pas ajouter un juge a cette epreuve, les 3 juges sont deja rempli " << endl;
                        }
                        break;
                    }
                }
                if (i == t->list_epr.size())
                    cout << "Erreur,epreuve inexistant" << endl;
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    void Supprimer(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                cout << "saisir l'id de Juge que vous voulez supprimer" << endl;
                int idj;
                cin >> idj;
                cout << "saisir l'id de l'epreuve concernee" << endl;
                int idep;
                cin >> idep;
                int i;
                for (i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->id == idep)
                    {
                        if (t->list_epr[i]->initializee == false)
                        {
                            for (int j = 0; j < t->list_epr[i]->les_juges.size(); j++)
                            {
                                if (t->list_epr[i]->les_juges[j]->getid() == idj)
                                {
                                    delete (t->list_epr[i]->les_juges[j]);
                                    t->list_epr[i]->les_juges.erase(t->list_epr[i]->les_juges.begin() + j);
                                    break;
                                }
                            }
                        }
                        else
                            cout << "vous ne pouvez pas supprimer de cette epreuve car elle est initialisee" << endl;
                        break;
                    }
                }
                if (i == t->list_epr.size())
                    cout << "Erreur,epreuve inexistant" << endl;
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    organisateur_Juge &operator=(const organisateur_Juge &o)
    {
        if (this != &o)
        {
            for (auto &pair : list_Juges)
            {
                for (int i = 0; i < pair.second.size(); i++)
                {
                    delete (pair.second[i]);
                }
                pair.second.clear();
            }
            organisateur::operator=(o);
            for (const auto &pair : o.list_Juges)
            {
                list_Juges.insert(pair);
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &, organisateur_Juge &);
    friend istream &operator>>(istream &, organisateur_Juge &);
};
ostream &operator<<(ostream &x, organisateur_Juge &o)
{
    organisateur *q = &o;
    x << *q;
    x << "les juges enregistrees par vous" << endl;
    for (const auto &pair : o.list_Juges)
    {
        x << "--------------------------->id de l'epreuve : " << pair.first << endl;
        x << "Les juges" << endl;
        for (int i = 0; i < pair.second.size(); i++)
        {
            x << *pair.second[i] << endl;
        }
    }
    return x;
}
istream &operator>>(istream &x, organisateur_Juge &o)
{
    organisateur *q = &o;
    x >> *q;
    return x;
}

class organisateur_Recompense : public organisateur
{
    map<int, vector<gagnant *>> list_gagnants;

public:
    organisateur_Recompense(int n = 1, string nn = "", string p = "", int i = 0, int num = 0, string ad = "") : organisateur(nn, p, i, num, ad)
    {
    }
    ~organisateur_Recompense()
    {
        for (auto &pair : list_gagnants)
        {
            for (int i = 0; i < pair.second.size(); i++)
            {
                delete (pair.second[i]);
            }
            pair.second.clear();
        }
    }
    void Assigner(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                int idr;
                cout << "donner l'id de la recompense que vous voulez l'affecter" << endl;
                cin >> idr;
                int id_eqp;
                cout << "donner l'id de l'equipe" << endl;
                cin >> id_eqp;
                int idp;
                cout << "donner l'id de l'epreuve" << endl;
                cin >> idp;
                cout << "saisir la date d'obtention" << endl;
                Date d;
                cin >> d;
                int i;
                for (i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->getid() == idp)
                    {
                        int j;
                        for (j = 0; j < t->list_epr[i]->les_restant.size(); j++)
                        {
                            if (t->list_epr[i]->les_restant[j]->getid() == id_eqp)
                            {
                                int k;
                                for (k = 0; k < t->list_epr[i]->les_recomp.size(); k++)
                                {
                                    cout << *t->list_epr[i]->les_recomp[k] << endl
                                         << endl
                                         << endl
                                         << endl
                                         << endl;
                                    if (t->list_epr[i]->les_recomp[k]->id_rec == idr)
                                    {
                                        cout << "+++++++++++++++++++++++++++" << endl;
                                        gagnant g;
                                        Equipe *e = &g;
                                        *e = *t->list_epr[i]->les_restant[j];
                                        g.r = *t->list_epr[i]->les_recomp[k];
                                        g.date_d_obtention = d;
                                        gagnant *q = new gagnant(g);
                                        t->list_epr[i]->les_gagnant.push_back(q);
                                        t->list_epr[i]->les_restant.erase(t->list_epr[i]->les_restant.begin() + j);
                                        cout << "+++++++++++++++++++++++++++" << endl;
                                        gagnant *v = new gagnant(g.id_eqp);
                                        if (list_gagnants.count(t->list_epr[i]->getid()) > 0)
                                        {
                                            list_gagnants[t->list_epr[i]->getid()].push_back(v);
                                        }
                                        else
                                        {
                                            pair<int, vector<gagnant *>> p(t->list_epr[i]->getid(), {v});
                                            list_gagnants.insert(p);
                                        }
                                        break;
                                    }
                                }
                                if (k == t->list_epr[i]->les_recomp.size())
                                {
                                    cout << "Erreur recompense" << endl;
                                }
                                break;
                            }
                        }
                        if (j == t->list_epr[i]->les_restant.size())
                        {
                            cout << "Erreur equipe" << endl;
                        }
                        break;
                    }
                }
                if (i == t->list_epr.size())
                {
                    cout << "Erreur cette epreuve n'existe pas" << endl;
                }
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    void Ajouter(Tournoi *t)
    {

        while (1)
        {
            if (this->auth == true)
            {
                cout << "saisir l'id de l'epreuve concernee" << endl;
                int idep;
                cin >> idep;
                int i;
                for (i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->id == idep)
                    {
                        if (t->list_epr[i]->les_recomp.size() < 3)
                        {
                            Recompense r;
                            cin >> r;
                            Recompense *q = new Recompense(r);
                            t->list_epr[i]->les_recomp.push_back(q);
                            break;
                        }
                        else
                        {
                            cout << "vous ne pouvez pas ajouter a cette epreuve , les 3 recompenses sont deja enregistrees" << endl;
                            break;
                        }
                    }
                }
                if (i == t->list_epr.size())
                    cout << "Erreur,epreuve inexistant" << endl;
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    }
    void afficher()
    {
        organisateur::afficher();
        cout << "les gagnants enregistrees par vous :" << endl;
        for (const auto &pair : list_gagnants)
        {
            cout << "--------------------------->id de l'epreuve : " << pair.first << endl;
            cout << "Les gagnants" << endl;
            for (int i = 0; i < pair.second.size(); i++)
            {
                cout << *pair.second[i] << endl;
            }
        }
    }
    void modifierRecomp(Epreuve *e, int idd)
    {
        for (int i = 0; i < e->les_recomp.size(); i++)
        {
            if (e->les_recomp[i]->id_rec == idd)
            {
                e->les_recomp[i]->modifier();
            }
        }
    }
    void modifierGagnant(Epreuve *e, int id)
    {
        for (int i = 0; i < e->les_gagnant.size(); i++)
        {
            if (e->les_gagnant[i]->id_eqp == id)
            {
                e->les_gagnant[i]->modifier();
            }
        }
    }
    void SupprimerRec(Tournoi *t)
    {
        while (1)
        {
            if (this->auth == true)
            {
                cout << "saisir l'id de l'epreuve concernee" << endl;
                int idep;
                cin >> idep;
                int idrec;
                cout << "saisir l'id de la recompense a supprimer" << endl;
                cin >> idrec;
                int i;
                for (i = 0; i < t->list_epr.size(); i++)
                {
                    if (t->list_epr[i]->id == idep)
                    {
                        if (t->list_epr[i]->initializee == false)
                        {
                            for (int j = 0; j < t->list_epr[i]->les_recomp.size(); j++)
                            {
                                if (t->list_epr[i]->les_recomp[j]->id_rec == idrec)
                                {
                                    delete (t->list_epr[i]->les_recomp[j]);
                                    t->list_epr[i]->les_recomp.erase(t->list_epr[i]->les_recomp.begin() + j);
                                }
                            }
                            break;
                        }
                        else
                            cout << "vous ne pouvez pas supprimer de cette epreuve car elle est initialisee" << endl;
                    }
                }
                if (i == t->list_epr.size())
                    cout << "Erreur,epreuve inexistant" << endl;
                break;
            }
            else
            {
                cout << "veuillez vous authentifier" << endl;
                bool b = s_authentifier();
                if (!b)
                    break;
            }
        }
    };
    void Afficher_gagnants(Epreuve *e, int id)
    {
        for (int i = 0; i < e->les_gagnant.size(); i++)
        {
            if (e->les_gagnant[i]->id_eqp == id)
            {
                cout << *e->les_gagnant[i];
            }
        }
    }
    void Afficher_Recompenses(Epreuve *e, int idd)
    {
        for (int i = 0; i < e->les_recomp.size(); i++)
        {
            if (e->les_recomp[i]->id_rec == idd)
            {
                cout << *e->les_recomp[i];
            }
        }
    };
    organisateur_Recompense &operator=(const organisateur_Recompense &o)
    {
        if (this != &o)
        {
            for (auto &pair : list_gagnants)
            {
                for (int i = 0; i < pair.second.size(); i++)
                {
                    delete (pair.second[i]);
                }
                pair.second.clear();
            }
            organisateur::operator=(o);
            for (auto &pair : list_gagnants)
            {
                list_gagnants.insert(pair);
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &, organisateur_Recompense &);
    friend istream &operator>>(istream &, organisateur_Recompense &);
};
ostream &operator<<(ostream &x, organisateur_Recompense &o)
{
    organisateur *q = &o;
    x << *q;
    x << "les gagnants enregistrees par vous :" << endl;
    for (const auto &pair : o.list_gagnants)
    {
        x << "--------------------------->id de l'epreuve : " << pair.first << endl;
        x << "Les gagnants" << endl;
        for (int i = 0; i < pair.second.size(); i++)
        {
            x << *pair.second[i] << endl;
        }
    }
    return x;
}
istream &operator>>(istream &x, organisateur_Recompense &o)
{
    organisateur *q = &o;
    x >> *q;
    return x;
}

/* vector<Equipe*> copyVector(const vector<Equipe*>& original) {
    vector<Equipe*> copy;
    Equipe*p;
    for(int i=0;i<original.size();i++){
        if(typeid(*original[i])==typeid(solo)){
        p=new solo(static_cast<const solo&>(*(original[i])));
        }
        else if(typeid(*original[i])==typeid(duo)){
        p=new duo(static_cast<const duo&>(*(original[i])));
        }
        else if(typeid(*original[i])==(typeid(squad))) {
        p=new squad(static_cast<const squad&>(*(original[i])));
        }
        else{
            p=new Equipe(*original[i]);
        }
     copy.push_back(p);
    }
    return copy;
}









 while(1){
        if(this->auth==true){




            break;
        }
        else{
        cout<<"veuillez vous authentifier pour ajouter des Recompenses"<<endl;
        bool b=s_authentifier();
        if (!b)break;
        }
        }
 */
