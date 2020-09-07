class Ans
    attr_accessor :N, :M
    
    def initialize(n:, m:)
        @N = n 
        @M = m
    end

    def solve
        if @N == @M
            'Yes'
        else
            'No'
        end
    end

end

N,M = gets.chomp.split.map(&:to_i)
ans = Ans.new(n: N,m: M)
puts ans.solve
