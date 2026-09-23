#ifndef NOMBRE_HPP
#define NOMBRE_HPP

#ifdef VERSION_COMPLETE

// Version complète de la classe
class Nombre {
   public :
      Nombre(int valeur);
      void afficher() const;

   private :
      int m_valeur;
};

#else

// Coquille vide
class Nombre {

};

#endif // VERSION COMPLETE
#endif // NOMBRE_HPP