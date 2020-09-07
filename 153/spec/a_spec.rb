require './A.rb'

RSpec.describe Ans do
    describe '#initialize' do
        it 'set_N' do
            expect(Ans.new(na: 1,aa: 3).N).to eq 1
        end

        it 'set_A' do
            expect(Ans.new(na: 1,aa: 3).A).to eq 3
        end
    end

    describe '#solve' do
        let(:ans){ Ans.new(na: nnn,aa: aaa) }
        subject{ ans.solve }

        context 'sample_1' do
            let(:nnn){ 10 }
            let(:aaa){ 4 }
            it{ is_expected.to eq 3}
        end

        context 'sample_2' do
            let(:nnn){ 1 }
            let(:aaa){ 10000 }
            it { is_expected.to eq 1}
        end

        context 'sample_3' do
            let(:nnn){ 10000 }
            let(:aaa){ 1 }
            it{ is_expected.to eq 10000}
        end

    end
end

