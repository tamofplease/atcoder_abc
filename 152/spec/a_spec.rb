require './A.rb'

RSpec.describe 'A' do
    describe '#initialize' do
        let(:ans) { Ans.new(n:3, m:4)}
        it 'input_N' do
            expect(ans.N).to eq 3
        end

        it 'input_M' do
            expect(ans.M).to eq 4
        end

    end

    describe '#solve' do
        let(:ans){ Ans.new(n: nn,m: mm) }
        subject{ ans.solve }

        shared_examples 'AC' do
            it { is_expected.to eq 'Yes'}
        end

        shared_examples 'WA' do
            it{ is_expected.to eq 'No'}
        end

        context 'exp_1' do
            let(:nn){ 3 }
            let(:mm){ 3 }
            it_behaves_like 'AC'
        end

        context 'exp_2' do
            let(:nn){ 3 }
            let(:mm){ 4 }
            it_behaves_like 'WA'
        end

        context 'exp_3' do
            let(:nn){ 1 }
            let(:mm){ 1 }
            it_behaves_like 'AC'
        end
    end
end

