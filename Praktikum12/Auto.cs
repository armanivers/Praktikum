namespace Praktikum12
{
    public class Auto
    {
        public Auto(string hersteller,int baujahr)
        {
            this.Hersteller = hersteller;
            this.Baujahr = baujahr;
        }
        //private string hersteller;
        public string Hersteller {get; set;}


        // so kriege ich stackoverflow?
        /*
        public string Hersteller 
        {
            get
            {
                return Hersteller;
            }
            set
            {
                Hersteller = value;
            }
        }
        */

        // private int baujahr;
        // Automatic Property
        public int Baujahr {get; set;}

        public override string ToString()
        {
            return "Hersteller: " + Hersteller + ", Baujahr " + Baujahr;
        }
    }
}