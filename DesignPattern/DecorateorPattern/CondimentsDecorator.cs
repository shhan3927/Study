using System;

namespace DecorateorPattern
{
    abstract class CondimentDecorator : Beverage
    {
        public new abstract String GetDesc();
    }

    class Mocha : CondimentDecorator
    {
        private Beverage beverage;

        public Mocha(Beverage b)
        {
            beverage = b;
        }

        public override String GetDesc()
        {
            return beverage.GetDesc() + ", 모카";
        }

        public override double Cost()
        {
            return .20 + beverage.Cost();
        }
    }

    //////////////////////////////////////

    class Whip : CondimentDecorator
    {
        private Beverage beverage;

        public Whip(Beverage b)
        {
            beverage = b;
        }

        public override String GetDesc()
        {
            return beverage.GetDesc() + ", 휘핑";
        }

        public override double Cost()
        {
            return .10 + beverage.Cost();
        }
    }
}