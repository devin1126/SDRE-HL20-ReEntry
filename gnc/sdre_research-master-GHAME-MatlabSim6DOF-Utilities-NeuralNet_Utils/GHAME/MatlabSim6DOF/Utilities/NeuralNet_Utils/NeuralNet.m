classdef NeuralNet
    %% Properties
    properties
        ninput
        noutput
        nlayers
        WW
        VV
        SS
        dd
    end % End of Properties
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    %% Methods
    methods
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function yout = Sigmoid(~,nin)
%             yout = (exp(nin) - 1.0)/(exp(nin) + 1.0);
            yout = exp(-nin.^2);
%             yout = nin.^2;
%             yout = tanh(nin);
%             yout = exp(-nin);
%             yout = sin(nin) + cos(nin);
            return
        end % End of Sigmoid

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function yout = DSigmoid(~,nin)
%             yout = (exp(nin) - 1.0)/(exp(nin) + 1.0);
            yout = -2.*nin.*exp(-nin.^2);
            return
        end % End of Sigmoid
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        function obj = NN_Initialize(obj, Ninput, Nlayers, Noutput)
            obj.WW = randn(Nlayers,Ninput);
            obj.SS = zeros(Nlayers,1);
            obj.VV = zeros(Nlayers,Noutput);
            obj.dd = zeros(Nlayers,1);
            
            obj.ninput = Ninput;
            obj.noutput = Noutput;
            obj.nlayers = Nlayers;
            
            return;
        end % End of NN_Initialize
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Algebraic Training
        function obj = NN_Train(obj, Xtrain, Ytrain)
            fprintf('Training the Neural Network using Algebraic Training\n');
            
            % Number of Training Samples
            nsamples = length(Xtrain);
            SSu = zeros(nsamples, obj.nlayers);
            
            % Bias Computation
            obj.dd = -diag(Xtrain*obj.WW');
            
            % Algebraic Training
            for i = 1:nsamples
                xx = Xtrain(i,:)';
                
                %% Input Layer
                nn = obj.WW*xx + obj.dd;
                
                %% Hidden Layer
                a1 = length(nn);
                obj.SS = zeros(a1,1);
                for ii = 1:a1
                    nin = nn(ii);
                    obj.SS(ii) = obj.Sigmoid(nin);
                end
                
                SSu(i,:) = obj.SS';
                
            end
            
            fprintf('Rank of SSu = %15.5f\n',rank(SSu));
            fprintf('Number of Layers = %15.5f\n',obj.nlayers);
            
            %% Output Weights
            obj.VV = pinv(SSu)*Ytrain';
            
            fprintf('Training Complete\n');
            
            return;
        end % End of NN_Train
        
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Evaluation
        function yout = NN_Eval( obj, Xin)
            % Output Net
            nn = obj.WW*Xin + obj.dd;
            
            %% Hidden Layer
            Sa = obj.Sigmoid(nn);
            
            yout = obj.VV'*Sa;
            
            return;
        end % End of NN_Eval

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Evaluation
        function yout = DNN_Eval( obj, Xin)
            % Output Net
            nn = obj.WW*Xin + obj.dd;
            
            %% Hidden Layer
            DSa = obj.DSigmoid(nn);
            
            yout = obj.VV'*(DSa.*obj.WW);
            
            return;
        end % End of NN_Eval
        
    end % End of Methods
    
end % End of Class