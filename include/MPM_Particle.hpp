class MPMParticle {
  public:
      int ID;                   // The Particles Id
      double Coordinate[3];     // The Particles Spatial Coordinate
      double density;           // The Particles Material Density
      double Volume;            // The Particles Volume
      double Mass;              // The Particles Mass

      double getMass(void);     // A Member Function that returns the Current Mass of the Particle  MemberFunction: hass access to all data of the object
      void Report(void);        // A Member Function to print out a report of this object

  private:
};
