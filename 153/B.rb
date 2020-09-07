class Ans
    attr_accessor :H,:N
    attr_accessor :A
    def initialize(hp: ,num: ,ans: )
        @H = hp
        @N = num
        @A = ans
    end

    def solve
        cou = 0
        for num in @A do
            cou += num
        end
        puts @N
        if cou >= @H
            "Yes"
        else
            "No"
        end
    end
end

H,N = gets.chomp.split.map(&:to_i)
A = gets.chomp.split.map(&:to_i)

ans = Ans.new(hp: H,num: N,ans: A)
puts ans.solve