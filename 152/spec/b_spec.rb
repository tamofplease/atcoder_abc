require './B.rb'

RSpec.describe 'Ans' do

    describe '#initialize' do
        let(:ans){ Ans.new(a:4,b:3)}
        it 'is_A' do
            expect(ans.A).to eq 4
        end

        it 'is_B' do
            expect(ans.B).to eq 3
        end
    end

    describe 'get_some' do
        let(:ans){ Ans.new(a: 4,b: 3) }

        it 'get_c' do
            expect(ans.get_c).to eq 3333
        end

        it 'get_d' do
            expect(ans.get_d).to eq 444
        end
    end

    describe 'get_ans' do
        let(:ans){ Ans.new(a: aa,b: bb)}
        subject{ ans.solve }
        context 'exp_1' do
            let(:aa){ 4 }
            let(:bb){ 3 }
            it{ is_expected.to eq 3333}
        end

        context 'exp_2' do
            let(:aa){ 7 }
            let(:bb){ 7 }
            it{ is_expected.to eq 7777777}
        end
    end
    
    

end
