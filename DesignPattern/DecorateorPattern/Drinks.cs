namespace DecorateorPattern
{
    class Espresso : Beverage
    {
        public Espresso()
        {
            Description = "에스프레소";
        }

        public override double Cost()
        {
            return 1.99;
        }
    }

    class HouseBlend : Beverage
    {
        public HouseBlend()
        {
            Description = "하우스 블렌드 커피";
        }

        public override double Cost()
        {
            return .89;
        }
    }
}