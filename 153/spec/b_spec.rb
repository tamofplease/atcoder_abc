require './B.rb'

RSpec.describe Ans do
    describe '#initialize' do
        let(:ans){ Ans.new(params)}
        let(:params){ {hp: 10,num: 3,ans: [4,5,6]} }
        it 'set_H' do
            expect(ans.H).to eq 10
        end
        it 'set_N' do
            expect(ans.N).to eq 3
        end
        it 'set_A' do
            expect(ans.A).to eq [4,5,6]
        end
    end

    describe 'solve' do
        let(:ans){ Ans.new(hp: ha,num: na,ans: aa)}
        subject{ ans.solve }

        context 'sample_1' do
            let(:ha){ 10 }
            let(:na){ 3 }
            let(:aa){ [4,5,6] } 
            it{ is_expected.to eq 'Yes'}
        end

        context 'sample_2' do
            let!(:ha){ 20 }
            let!(:na){ 3 }
            let!(:aa){ [4,5,6] }
            it{ is_expected.to eq 'No'}
        end

        context 'sample_3' do
            let(:ha){ 210 }
            let(:na){ 5 }
            let(:aa){ [31,41,59,26,53] }
            it{ is_expected.to eq 'Yes'}
        end

        context 'sample_4' do
            let(:ha){ 211 }
            let(:na){ 5 }
            let(:aa){[31,41,59,26,53]}
            it{ is_expected.to eq 'No'}
        end



    end
end
