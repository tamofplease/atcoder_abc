class Ans
    attr_accessor :A, :B

    def initialize(a:,b:)
        @A = a
        @B = b
    end

    def get_c
        c = 0
        for i in 1..@A do 
            c *= 10
            c += @B
        end
        c
    end

    def get_d
        d = 0
        for i in 1..@B do
            d *= 10
            d += @A
        end
        d
    end

    def solve 
        if get_d > get_c
            get_d
        else 
            get_c
        end
    end
end

a,b = gets.chomp.split.map(&:to_i)
ans = Ans.new(a: a,b: b)
puts ans.solve
