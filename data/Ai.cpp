#include "Ai.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

// Constructor / Destructor
    // Constructor
        Ai::Ai()
        {

        }
        Ai::Ai(sf::Vector2f positionuser, sf::Vector2f positiontarget)
        {
            m_Target.x = positiontarget.x;
            m_Target.y = positiontarget.y;

            m_User.x = positionuser.x;
            m_User.y = positionuser.y; 
        }
    
    // destructor
        Ai::~Ai()
        {

        }

// Accessor

// function public

// function private

    // A*
        void Ai::compare(Noeud noeud1, Noeud noeud2)
        {
            if(noeud1.heuristique < noeud2.heuristique)
            {
                m_valuecompare = 1;
            }
            else if(noeud1.heuristique == noeud2.heuristique)
            {
                m_valuecompare = 0;
            }
            else
            {
                m_valuecompare = -1;
            }
        }
        void Ai::aStarExe()
        {
            std::vector<sf::Vector2f> closedList;
            /*
            m_OpenList = FilePrioritaire(comparateur=compare2Noeuds)
            openList.ajouter(depart)
            tant que openList n'est pas vide
                u = openList.defiler()
                si u.x == objectif.x et u.y == objectif.y
                    reconstituerChemin(u)
                    terminer le programme
                pour chaque voisin v de u dans g
                    si non(v existe dans closedList ou v existe dans openList avec un coût inférieur)
                            v.cout = u.cout +1 
                            v.heuristique = v.cout + distance([v.x, v.y], [objectif.x, objectif.y])
                            openList.ajouter(v)
                closedList.ajouter(u)
            terminer le programme (avec erreur)
            */
        }
    
    // djikstra
        void Ai::djikstraInit(std::vector<Noeud> listenoeud)
        {
            for(int noeud = 0; noeud < listenoeud.size(); noeud++)
            {
                
            }
            /*
            Initialisation(G,sdeb)
            1 pour chaque point s de G faire
            2    s.cout := infini             /* on initialise les sommets autres que sdeb à infini *//*
            3 fin pour
            4 d[sdeb] := 0                  /* la distance au sommet de départ sdeb est nulle */
        }
        void Ai::djikstraExe()
        {
            std::vector<Noeud> P;
        }
        void Ai::djikstraMin(std::vector<Noeud> road)
        {
            unsigned int min = -1;
            int top = -1;
            
            for(int t = 0; t < road.size(); t ++)
            {
                if(road[t].cout < min)
                {
                    min = road[t].cout;
                    /*
                    top = road[t];
                    */
                }
            }
            // return top;
        }
        void Ai::djikstraUpdate()
        {

        }

    // Weighted A*