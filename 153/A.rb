class Ans
    attr_accessor :N,:A
    def initialize(na: ,aa: )
        @N = na
        @A = aa
    end

    def solve
        if @A != 0
            if @N % @A != 0
                (@N/@A)+1
            else
                (@N/@A)
            end
        end
    end
end



N,A= gets.chomp.split.map(&:to_i)
ans = Ans.new(na: N,aa: A)
puts ans.solve